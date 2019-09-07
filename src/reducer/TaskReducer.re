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
        <input
          type_="checkbox"
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
