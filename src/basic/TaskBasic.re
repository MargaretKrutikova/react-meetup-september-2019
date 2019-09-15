[@react.component]
let make = (~task) =>
  <>
    <div className="task-row">
      {React.string("Task:")}
      <b> {React.string(task)} </b>
    </div>
    <button> {React.string("Complete")} </button>
  </>;
