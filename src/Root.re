[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();
  let task = "Fix that bug";

  <>
    <header>
      <a href="/basic" className="nav-link"> {React.string("Basic")} </a>
      <a href="/state" className="nav-link"> {React.string("State")} </a>
      <a href="/reducer" className="nav-link"> {React.string("Reducer")} </a>
    </header>
    <main>
      <div className="task-container">
        {switch (url.path) {
         | ["basic"] => <TaskBasic task />
         | ["state"] => <TaskState task />
         | ["reducer"] => <TaskReducer task />
         | _ => <div> {React.string("Not found")} </div>
         }}
      </div>
    </main>
  </>;
};
