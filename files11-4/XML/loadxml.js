var source; // XML-file (database)
var style;  // XSL-file (stylesheet)

//----------------------------------------
// loadXMLDoc
//----------------------------------------
function loadXMLDoc(dname) {
  if (window.ActiveXObject) {          // for IE only
    xmlDoc = new ActiveXObject("Microsoft.XMLDOM");
    xmlDoc.async=false;
    xmlDoc.load(dname);
    return xmlDoc;
    }
  // for other browsers
  xhttp = new XMLHttpRequest(); 
  xhttp.open("GET",dname,false);
  xhttp.send("");
  return xhttp.responseXML;
}
//----------------------------------------
// loadStyle
//----------------------------------------
function loadStyle ( styleName, id ) {
  style  = loadXMLDoc( styleName );
  if (window.ActiveXObject) {           // for IE only
    res = source.transformNode(style);
    document.getElementById(id).innerHTML = res;
    }
  else if (document.implementation && document.implementation.createDocument)
    {                                  // for other browsers
    xsltProcessor=new XSLTProcessor();
    xsltProcessor.importStylesheet(style);
    resultDocument = xsltProcessor.transformToFragment(source,document);
    res = document.getElementById(id);
    while (res.hasChildNodes()) 
      res.removeChild(res.lastChild);
    res.appendChild(resultDocument);
    }
}
