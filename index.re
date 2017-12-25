[@bs.module] external logo: string = "./logo.svg";

[%bs.raw {|require('./index.css')|}];

[@bs.val] external hot: bool = "module.hot";
[@bs.val] external accept: unit => unit = "module.hot.accept";

module App = {
  let component = ReasonReact.statelessComponent("App");
  let make = (~message, _children) => {
    ...component,
    render: (_self) =>
      <div className="App">
        <img src=logo className="App-logo" alt="logo" />
        <h1 className="App-Title">(ReasonReact.stringToElement("Hello Parcel x Reason React"))</h1>
        <h2>(ReasonReact.stringToElement(message))</h2>
      </div>
  }
};

ReactDOMRe.renderToElementWithId(<App message="Welcome to React and Reason" />, "root");

/* Hot Module Replacement */
if (hot) {
  accept()
};
