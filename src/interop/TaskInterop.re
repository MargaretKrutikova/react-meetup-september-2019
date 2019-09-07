let str = React.string;

type state = {
  completedAt: string,
  isNotified: bool,
};

type action =
  | CompleteTask(Js.Date.t)
  | ToggleNotifications;

let reducer = (state, action) => {
  switch (action) {
  | CompleteTask(date) => {
      ...state,
      completedAt: Js.Date.toLocaleTimeString(date),
    }
  | ToggleNotifications => {...state, isNotified: !state.isNotified}
  };
};

let initialState = {completedAt: "", isNotified: false};

module ReactSwitch = {
  [@bs.module "react-switch"] [@react.component]
  external make:
    (~checked: bool, ~onChange: bool => unit, ~className: string=?) =>
    React.element =
    "default";
};

[@react.component]
let make = (~task) => {
  let (state, dispatch) = React.useReducer(reducer, initialState);
  let {isNotified, completedAt} = state;

  <>
    <div className="task-row"> {str("Task:")} <b> {str(task)} </b> </div>
    <div className="task-row">
      {str("Completed:")}
      <b> {str(completedAt)} </b>
    </div>
    <div className="task-row">
      <label>
        <ReactSwitch
          className="switch"
          checked=isNotified
          onChange={_ => dispatch(ToggleNotifications)}
        />
        {str("Notify")}
      </label>
    </div>
    <button onClick={_ => dispatch(CompleteTask(Js.Date.make()))}>
      {str("Complete")}
    </button>
  </>;
};
