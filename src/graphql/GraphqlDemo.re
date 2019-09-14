[@react.component]
let make = () => {
  let (value, setValue) = React.useState(() => "react");
  let (searchQuery, setSearchQuery) = React.useState(() => "react");

  <>
    <form
      className="search-form"
      onSubmit={event => {
        ReactEvent.Form.preventDefault(event);
        setSearchQuery(_ => value);
      }}>
      <div className="input-container search-input">
        <input
          value
          type_="search"
          onChange={event => {
            let val_ = ReactEvent.Form.target(event)##value;
            setValue(val_);
          }}
        />
      </div>
      <button type_="submit"> {React.string("Go")} </button>
    </form>
    <GithubSearch query=searchQuery />
  </>;
};
