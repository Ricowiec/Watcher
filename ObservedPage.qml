import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

Page {
    id: page

    header: ToolBar {
        id: toolBar
        height: parent.height * 0.1
        width: parent.width
        x: 0
        y: 0

        Image {
            id: spyImage
            mipmap: true
            anchors.centerIn: parent
            height: parent.height * 0.7
            width: height
            source: "/Menu/Icons/spy3.png"
        }

        background: Rectangle {
            color: "#6666cc"
        }
    }

    ScrollView {
        anchors.fill: parent
        height: parent.height - parent.height * 0.1
        y: parent.height * 0.1

        ListView {
            id: objectsList
            anchors.fill: parent

            model: ListModel {
                id: objectsListModel
            }

            Component.onCompleted: {
                objectsListModel.append({
                                           objectNameID: "id",
                                           objectNameText: "Przykład nazwy",
                                           objectKRSID: "id2",
                                           objectKRSText: "KRS: " + "0000748294"
                                        });
            }

            delegate: Item {
                width: parent.width
                height: objectNameID.height * 1.5

                Text {
                    id: objectNameID
                    text: objectNameText
                    font.pixelSize: page.font.pixelSize
                    color: "#6666cc"

                    anchors.verticalCenter: parent.verticalCenter
                    x: parent.width * 0.02
                }

                Text {
                    id: objectKRSID
                    text: objectKRSText
                    font.pixelSize: page.font.pixelSize
                    color: "#6666cc"

                    anchors.verticalCenter: parent.verticalCenter
                    x: parent.width - width - parent.width * 0.02
                }

                Rectangle {
                    width: parent.width
                    height: 1
                    color: "#6666cc"
                    anchors.bottom: parent.bottom
                }
            }
        }
    }
}
