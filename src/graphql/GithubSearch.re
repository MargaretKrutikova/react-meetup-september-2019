type stargazers = {totalCount: int};

type repository = {
  nameWithOwner: string,
  stargazers,
  description: option(string),
};

module GithubSearchQueryConfig = [%graphql
  {|
    query($repo: String!, $owner: String!) {
      repository(name: $repo, owner: $owner) @bsRecord {
        nameWithOwner
        description
        stargazers @bsRecord {
          totalCount
        }
      }
    }
  |}
];

module GithubSearchQuery =
  ReasonApolloHooks.Query.Make(GithubSearchQueryConfig);

[@react.component]
let make = (~owner, ~repo) => {
  let query = GithubSearchQueryConfig.make(~owner, ~repo, ());

  let (response, _) = GithubSearchQuery.use(~variables=query##variables, ());

  switch (response) {
  | NoData => React.string("You haven't searched yet")
  | Loading => React.string("Loading...")
  | Error(_) => React.string("Not found")
  | Data(data) =>
    data##repository
    ->Belt.Option.mapWithDefault(React.null, repo =>
        <div className="search-result" key={repo.nameWithOwner}>
          {React.string(repo.nameWithOwner)}
          <div className="repo-stars">
            <span className="star-icon" />
            {repo.stargazers.totalCount |> string_of_int |> React.string}
          </div>
          <div className="repo-desc">
            {repo.description->Belt.Option.getWithDefault("") |> React.string}
          </div>
        </div>
      )
  };
};
