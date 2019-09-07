let str = React.string;

[@react.component]
let make = (~task) => {
  let (isOpen, setIsOpen) = React.useState(() => false);
  let handleToggle = _ => setIsOpen(prevState => !prevState);

  <>
    <button onClick=handleToggle className="toggle-btn">
      {str(isOpen ? "Hide" : "Show")}
    </button>
    {isOpen
       ? <>
           <div className="task-row"> {str("Task: " ++ task)} </div>
           <button> {React.string("Complete")} </button>
         </>
       : React.null}
  </>;
};
