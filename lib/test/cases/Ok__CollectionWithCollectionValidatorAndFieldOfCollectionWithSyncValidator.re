module Form = [%form
  type input = {authors: [@field.collection] array(author)}
  and author = {name: string};
  let validators = {
    authors: {
      collection: _input => Ok(),
      fields: {
        name: {
          strategy: OnSubmit,
          validate: ({authors, _}, ~at) =>
            Ok(authors->Belt.Array.getUnsafe(at).name),
        },
      },
    },
  }
];
