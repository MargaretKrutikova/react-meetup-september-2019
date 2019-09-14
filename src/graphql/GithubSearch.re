type stargazers = {totalCount: int};

type repository = {
  nameWithOwner: string,
  stargazers,
};

module GithubSearchQueryConfig = [%graphql
  {|
    query($query: String!) {
      search(query: $query, type: REPOSITORY, first: 20)  {
        nodes  {
          ... on Repository @bsRecord {
            nameWithOwner
            stargazers @bsRecord { totalCount }
          }
        }
      }
    }
  |}
];

module GithubSearchQuery =
  ReasonApolloHooks.Query.Make(GithubSearchQueryConfig);

[@react.component]
let make = (~query) => {
  let variables = GithubSearchQueryConfig.make(~query, ())##variables;
  let (searchData, _) = GithubSearchQuery.use(~variables, ());

  <div className="search-results">
    {switch (searchData) {
     | NoData => React.string("You haven't searched yet")
     | Loading => React.string("Loading...")
     | Error(_) => React.string("Ooops...")
     | Data(results) =>
       <>
         {SearchUtils.transformResult(
            results##search##nodes,
            repo => repo.stargazers.totalCount,
            repo =>
              <div className="search-result" key={repo.nameWithOwner}>
                {React.string(repo.nameWithOwner)}
                <div className="repo-stars">
                  <span className="star-icon" />
                  {repo.stargazers.totalCount |> string_of_int |> React.string}
                </div>
              </div>,
          )
          ->React.array}
       </>
     }}
  </div>;
};
