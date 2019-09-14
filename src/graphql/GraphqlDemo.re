type state = {
  owner: string,
  repo: string,
  ownerQuery: string,
  repoQuery: string,
};

type action =
  | EnterOwner(string)
  | EnterRepo(string)
  | SubmitSearch;

let reducer = (state, action) => {
  switch (action) {
  | EnterOwner(owner) => {...state, owner}
  | EnterRepo(repo) => {...state, repo}
  | SubmitSearch => {...state, ownerQuery: state.owner, repoQuery: state.repo}
  };
};

[@react.component]
let make = () => {
  let (state, dispatch) =
    React.useReducer(
      reducer,
      {repo: "", owner: "", ownerQuery: "", repoQuery: ""},
    );

  let hasSearched = state.ownerQuery !== "" && state.repoQuery !== "";
  <>
    <form
      className="search-form"
      onSubmit={event => {
        ReactEvent.Form.preventDefault(event);
        dispatch(SubmitSearch);
      }}>
      <div className="input-container search-input">
        <input
          value={state.owner}
          type_="text"
          onChange={event => {
            let val_ = ReactEvent.Form.target(event)##value;
            dispatch(EnterOwner(val_));
          }}
          placeholder="owner"
        />
        <span className="delimiter"> {React.string("/")} </span>
        <input
          value={state.repo}
          type_="text"
          onChange={event => {
            let val_ = ReactEvent.Form.target(event)##value;
            dispatch(EnterRepo(val_));
          }}
          placeholder="repository"
        />
      </div>
      <button type_="submit"> {React.string("Go")} </button>
    </form>
    <div className="search-results">
      {hasSearched
         ? <GithubSearch owner={state.ownerQuery} repo={state.repoQuery} />
         : React.null}
    </div>
  </>;
};
