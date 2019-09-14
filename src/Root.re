open Router;

let str = React.string;

[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();
  let task = "Fix that bug";

  <>
    <header>
      <NavLink href="/"> {str("Home")} </NavLink>
      <NavLink href="/basic"> {str("Basic")} </NavLink>
      <NavLink href="/state"> {str("State")} </NavLink>
      <NavLink href="/reducer"> {str("Reducer")} </NavLink>
      <NavLink href="/interop"> {str("Interop")} </NavLink>
      <NavLink href="/graphql"> {str("GraphQL")} </NavLink>
    </header>
    <main>
      <div className="task-container">
        {switch (url.path) {
         | ["basic"] => <TaskBasic task />
         | ["state"] => <TaskState task />
         | ["reducer"] => <TaskReducer task />
         | ["interop"] => <TaskInterop task />
         | ["graphql"] => <GraphqlDemo />
         | _ => <Start />
         }}
      </div>
    </main>
  </>;
};
