let sortByStars = (sortByFn, left, right) => {
  switch (left, right) {
  | (Some(`Repository(l)), Some(`Repository(r))) =>
    sortByFn(r) - sortByFn(l)
  | _ => 0
  };
};

let transformResult = (result, sortBy, renderRepo) =>
  (
    result->Belt.Option.getWithDefault([||])
    |> Js.Array.sortInPlaceWith(sortByStars(sortBy))
  )
  ->Belt.Array.map(item =>
      switch (item) {
      | Some(`Repository(repo)) => renderRepo(repo)
      | _ => React.null
      }
    );
