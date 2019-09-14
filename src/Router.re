module Link = {
  let handleClick = event =>
    if (!ReactEvent.Mouse.defaultPrevented(event)) {
      ReactEvent.Mouse.preventDefault(event);

      let anchor = ReactEvent.Mouse.currentTarget(event);
      ReasonReactRouter.push(anchor##href);
    };

  [@react.component]
  let make = (~href, ~className=?, ~children) => {
    <a href onClick=handleClick ?className> children </a>;
  };
};

module NavLink = {
  [@react.component]
  let make = (~href, ~children) => {
    let url = ReasonReactRouter.useUrl();
    let isActive =
      url.path
      ->Belt.List.keep(p => p->Js.String.includes(href))
      ->Belt.List.length
      > 0;

    <Link href className={"nav-link" ++ (isActive ? " nav-link--active" : "")}>
      children
    </Link>;
  };
};
