[@bs.val] external token: string = "process.env.REACT_APP_GRAPHQL_TOKEN";

let graphqlUrl = "https://api.github.com/graphql";

let makeClient = () => {
  let headers = {"authorization": "Bearer " ++ token};

  let authLink = ApolloLinks.createContextLink(() => {"headers": headers});
  let httpLink = ApolloLinks.createHttpLink(~uri=graphqlUrl, ());

  ReasonApollo.createApolloClient(
    ~link=ApolloLinks.from([|authLink, httpLink|]),
    ~cache=ApolloInMemoryCache.createInMemoryCache(),
    (),
  );
};

let client = makeClient();

ReactDOMRe.renderToElementWithId(
  <ReasonApollo.Provider client>
    <ReasonApolloHooks.ApolloProvider client>
      <Root />
    </ReasonApolloHooks.ApolloProvider>
  </ReasonApollo.Provider>,
  "root",
);
