import * as React from "react"

type Props = {
  task: string
}

type State = {
  isCompleted: boolean
  isNotified: boolean
}

type Action =
  | {
      type: "SetCompleted"
      isCompleted: boolean
    }
  | {
      type: "SetNotified"
      isNotified: boolean
    }

const reducer = (state: State, action: Action) => {
  switch (action.type) {
    case "SetCompleted":
      return { ...state, isCompleted: action.isCompleted }
    case "SetNotified":
      return { ...state, isNotified: action.isNotified }
  }
}

const initialState = { isCompleted: false, isNotified: false }

export const TaskPanel: React.FunctionComponent<Props> = ({ task }) => {
  const [state, dispatch] = React.useReducer(reducer, initialState)
  let { isNotified, isCompleted } = state

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
            onChange={_ =>
              dispatch({ type: "SetNotified", isNotified: !isNotified })
            }
          />
          Notify
        </label>
      </div>
      <button
        onClick={_ =>
          dispatch({ type: "SetCompleted", isCompleted: !isCompleted })
        }
      >
        {isCompleted ? "Reopen" : "Complete"}
      </button>
    </>
  )
}
