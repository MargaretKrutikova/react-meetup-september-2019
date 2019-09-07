[@react.component]
let make = (~task) => {
  <>
    <div className="task-row"> {React.string("Task: " ++ task)} </div>
    <button> {React.string("Complete")} </button>
  </>;
};
