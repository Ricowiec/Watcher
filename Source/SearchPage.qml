import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

import Watcher 1.0

Page {
    id: page

    header: ToolBar {
        id: searchBar
        height: parent.height * 0.1
        width: parent.width
        x: 0
        y: 0

        Image {
            id: previousArrow
            mipmap: true
            fillMode: Image.Stretch

            anchors.verticalCenter: parent.verticalCenter

            x: searchData.x / 2 - width / 2
            width: parent.height * 0.4
            height: parent.height * 0.4

            source:  "/Other/SearchPage/arrowLeft.png"

            MouseArea {
                anchors.fill: parent

                onClicked: {
                    console.log("LeftArrow clicked");

                    var currentPage = requester.getCurrentPage();
                    if(currentPage > 1)
                    {
                        requester.setCurrentPage(currentPage - 1);
                        callRequest();
                    }
                }
            }
        }

        Image {
            id: nextArrow
            mipmap: true
            fillMode: Image.Stretch

            anchors.verticalCenter: parent.verticalCenter

            x: searchData.x + searchData.width + searchData.x / 2 - width / 2
            width: parent.height * 0.4
            height: parent.height * 0.4

            source:  "/Other/SearchPage/arrowRight.png"

            MouseArea {
                anchors.fill: parent


                onClicked: {
                    console.log("RightArrow clicked");

                    requester.setCurrentPage(requester.getCurrentPage() + 1);
                    callRequest();
                }
            }
        }

        background: Rectangle {
            id: searchBarBackground
            anchors.fill: parent
            color: "#6666cc"
        }

        TextField {
            id: searchData
            inputMethodHints: Qt.ImhNoPredictiveText
            width: parent.width * 0.62; height: parent.height * 0.65
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            topPadding: height * 0.1
            color: "black"

//            text: "Rybnik"

            leftPadding: width * 0.065
            rightPadding: width * 0.065 + searchImage.width * 0.85
            bottomPadding: 0

            background: Rectangle {
                anchors.fill: parent
                radius: 15
            }

//            onTextChanged: {
//                console.log(text);
//            }

            Image {
                id: searchImage
                anchors.verticalCenter: parent.verticalCenter
                x: parent.width - width * 1.1
                width: parent.height * 0.9
                height: parent.height * 0.9
                mipmap: true
                source: "/Other/SearchPage/loupeSearch.png"
                fillMode: Image.Stretch

                MouseArea {
                    id: searchImageMouseArea
                    width: parent.width * 1.4
                    height: parent.height * 1.4
                    anchors.centerIn: parent

//                    Rectangle { // Collision check
//                        anchors.fill: parent
//                        color: "black"
//                    }

                    onClicked: {
                        Qt.inputMethod.hide();
                        objectsListModel.clear();
                        requester.setCurrentPage(1);
                        console.log("Search icon clicked");
                        callRequest();
                    }
                }
            }
        }
    }

    function callRequest() {
        objectsListModel.clear();
///                        Android
//                        console.log("SearchData.text: " + searchData.text);
//                        console.log("SearchData.text: " + searchData.getText(0, searchData.length));
        requester.request("https://api-v3.mojepanstwo.pl/dane/krs_podmioty.json?conditions[q]=" + searchData.text);
///                        Windows
//        requester.requestToCurl("https://api-v3.mojepanstwo.pl/dane/krs_podmioty.json?conditions[q]=" + searchData.text);
    }

    /// List of objects
    ScrollView {
        anchors.fill: parent
        height: parent.height - parent.height * 0.1
        y: searchBar.height * 1.2

        ListView {
            id: objectsList
            anchors.fill: parent
//            spacing: 6
//            spacing: 13

            delegate: Item {
                width: parent.width
//                height: objectsList.height * 0.08
                height: objectMainNameID.height * 2

                Text {
                    id: objectMainNameID
//                    y: parent.y * 1.15
                    anchors.verticalCenter: parent.verticalCenter
                    x: parent.width * 0.02
                    width: parent.width - x - objectKRSNameID.width - parent.width * 0.04

                    text: objectMainNameText
                    color: "#6666cc"
                    font.pixelSize: page.font.pixelSize * 0.95
                    wrapMode: Text.WordWrap
                }

                Text {
                    id: objectKRSNameID
                    anchors.verticalCenter: parent.verticalCenter
                    x: parent.width - parent.width * 0.02 - width
//                    width: parent.width - parent.width * 0.02

                    text: "KRS: " + objectKRSNameText
                    color: "#6666cc"
                    font.pixelSize: page.font.pixelSize * 0.85
                }

                MouseArea {
                    anchors.fill: parent

                    onClicked: {
                        console.log("Clicked on: " + objectMainNameID.text);
                        APIBridge.setObject(requester.getReturnedObject(objectMainNameID.text));
                        APIBridge.emitPushedPage();
                    }
                }

                Rectangle {
//                    x: parent.width * 0.05
//                    width: parent.width * 0.9
                    width: parent.width
                    height: 1
                    color: "#6666cc"
                    anchors.bottom: parent.bottom
                }
            }

            model: ListModel {
                id: objectsListModel
            }
        }

        Requester {
            id: requester

            onReadyRead: {
    //            console.log("ReadyRead data from Requester(qml)");
    //            console.log(getData("https://api-v3.mojepanstwo.pl/dane/krs_podmioty.json?conditions[q]=" + searchData.text))
//                requester.jsonParser(searchData.text);
//                console.log(requester.getObjectsList(searchData.text));
                var request = requester.getObjectsList(searchData.text);
                for(var i = 0; i < request.length; i += 2)
                {
//                    console.log("Creating object: " + i);
                    objectsListModel.append({
                                                objectMainNameID: request[i],
                                                objectMainNameText: request[i],
                                                objectKRSNameID: request[i + 1],
                                                objectKRSNameText: request[i + 1]
                                            });
                }
            }
        }
    }
}
