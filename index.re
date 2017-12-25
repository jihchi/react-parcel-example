[@bs.module] external logo : string = "./logo.svg";

[%bs.raw {|require('./index.css')|}];

[@bs.val] external hot : bool = "module.hot";

[@bs.val] external accept : unit => unit = "module.hot.accept";

module App = {
  let component = ReasonReact.statelessComponent("App");
  let make = (~message, _children) => {
    ...component,
    render: (_self) =>
      <div className="App">
        <div className="App-header">
          <img src=logo className="App-logo" alt="logo" />
          <h2> (ReasonReact.stringToElement(message)) </h2>
        </div>
        <p className="App-intro"> (ReasonReact.stringToElement("Hello Parcel x Reason React")) </p>
      </div>
  };
};

ReactDOMRe.renderToElementWithId(<App message="Welcome to React and Reason" />, "root");

/* Hot Module Replacement */
if (hot) {
  accept()
};