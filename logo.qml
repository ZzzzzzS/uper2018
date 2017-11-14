import QtQuick 2.7
import QtWebView 1.1
Item {
    id: logoview
    visible: true

    WebView
    {
        id:webView
        x:0
        y:0
        width: parent.width
        height: parent.height
        url: "http://zzshub.cn"
        scale: 1.0
    }

}

