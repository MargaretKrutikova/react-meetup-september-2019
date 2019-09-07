import * as React from "react"

type Props = {
  task: string
}

export const TaskBasic: React.FunctionComponent<Props> = ({ task }) => (
  <>
    <div className="task-row">
      Task: <b>{task}</b>
    </div>
    <button>Complete</button>
  </>
)
