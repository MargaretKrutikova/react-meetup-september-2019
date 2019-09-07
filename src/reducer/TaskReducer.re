let str = React.string;

type state = {
  isCompleted: bool,
  isNotified: bool,
};

type action =
  | SetCompleted(bool)
  | SetNotified(bool);

let reducer = (state, action) => {
  switch (action) {
  | SetCompleted(isCompleted) => {...state, isCompleted}
  | SetNotified(isNotified) => {...state, isNotified}
  };
};

let initialState = {isCompleted: false, isNotified: false};

[@react.component]
let make = (~task) => {
  let (state, dispatch) = React.useReducer(reducer, initialState);
  let {isNotified, isCompleted} = state;

  <>
    <div className="task-row"> {str("Task: " ++ task)} </div>
    <div className="task-row">
      {str("Status: " ++ (isCompleted ? "Done" : "Open"))}
    </div>
    <div className="task-row">
      <label>
        <input
          type_="checkbox"
          checked=isNotified
          onChange={_ => dispatch(SetNotified(!isNotified))}
        />
        {str("Notify")}
      </label>
    </div>
    <button onClick={_ => dispatch(SetCompleted(!isCompleted))}>
      {str(isCompleted ? "Reopen" : "Complete")}
    </button>
  </>;
};
