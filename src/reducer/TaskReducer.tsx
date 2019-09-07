import * as React from "react"

type Props = {
  task: string
}

type State = {
  completedAt: string
  isNotified: boolean
}

type Action =
  | {
      type: "CompleteTask"
      date: Date
    }
  | {
      type: "ToggleNotifications"
    }

const reducer = (state: State, action: Action): State => {
  switch (action.type) {
    case "CompleteTask":
      return { ...state, completedAt: action.date.toLocaleTimeString() }
    case "ToggleNotifications":
      return { ...state, isNotified: !state.isNotified }
  }
}

const initialState: State = { completedAt: "", isNotified: false }

export const TaskPanel: React.FunctionComponent<Props> = ({ task }) => {
  const [state, dispatch] = React.useReducer(reducer, initialState)
  let { isNotified, completedAt: isCompleted } = state

  return (
    <>
      <div className="task-row">Task: {task}</div>
      <div className="task-row">
        Status:
        {isCompleted ? "Done" : "Open"}
      </div>
      <div className="task-row">
        <label>
          <input
            type="checkbox"
            checked={isNotified}
            onChange={_ => dispatch({ type: "ToggleNotifications" })}
          />
          Notify
        </label>
      </div>
      <button
        onClick={_ => dispatch({ type: "CompleteTask", date: new Date() })}
      >
        Complete
      </button>
    </>
  )
}
