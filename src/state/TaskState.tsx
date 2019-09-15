import * as React from "react"

type Props = {
  task: string
}

export const TaskPanel: React.FunctionComponent<Props> = ({ task }) => {
  const [isOpen, setIsOpen] = React.useState(false)
  let handleToggle = () => setIsOpen(prevIsOpen => !prevIsOpen)

  return (
    <>
      <button onClick={handleToggle} className="toggle-btn">
        {isOpen ? "Hide" : "Show"}
      </button>
      {isOpen ? (
        <>
          <div className="task-row">
            Task: <b>{task}</b>
          </div>
          <button> Complete </button>
        </>
      ) : null}
    </>
  )
}
