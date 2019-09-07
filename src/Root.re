[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();
  let task = "Fix that bug";

  <>
    <header>
      <a href="/basic" className="nav-link"> {React.string("Basic")} </a>
      <a href="/state" className="nav-link"> {React.string("State")} </a>
      <a href="/reducer" className="nav-link"> {React.string("Reducer")} </a>
      <a href="/interop" className="nav-link"> {React.string("Interop")} </a>
    </header>
    <main>
      <div className="task-container">
        {switch (url.path) {
         | ["basic"] => <TaskBasic task />
         | ["state"] => <TaskState task />
         | ["reducer"] => <TaskReducer task />
         | ["interop"] => <TaskInterop task />
         | _ =>
           <div className="title">
             {React.string("Demo time")}
             <img
               height="50"
               src="https://assets.change.org/photos/9/ve/yo/BqVEYoWGFrIepAj-800x450-noPad.jpg?1558301066"
             />
           </div>
         }}
      </div>
    </main>
  </>;
};
