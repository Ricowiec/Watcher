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

        background: Rectangle {
            color: "#6666cc"
        }

        Image {
            id: previousArrow
            mipmap: true
            fillMode: Image.Stretch

            anchors.verticalCenter: parent.verticalCenter

            x: width
            width: parent.height * 0.4
            height: parent.height * 0.4

            source:  "/Other/SearchPage/arrowLeft.png"

            MouseArea {
//                anchors.fill: parent
                width: parent.width * 2
                height: parent.height * 2
                anchors.centerIn: parent

//                onReleased: {
//                    console.log("LeftArrow clicked");
//                    APIBridge.emitPopPage();
//                }

                onClicked: {
                    console.log("LeftArrow clicked");
                    APIBridge.emitPopPage();
                }

//                Rectangle {
//                    anchors.fill: parent
//                    color: "black"
//                }
            }
        }

        Image {
            id: observed
            mipmap: true
            fillMode: Image.Stretch

            anchors.verticalCenter: parent.verticalCenter

            x: parent.width - width * 1.5
            width: height
            height: parent.height * 0.4

            source:  "/DetailedPage/DetailedPage/heart.png"

            MouseArea {
                anchors.fill: parent

                onClicked: {
                    console.log("Heart clicked");
                }
            }
        }
    }


    ScrollView {
//        anchors.fill: parent
        x: 0; y: fullName.height * 1.5
//        height: parent.height - fullName.height * 1.5
//        height: fullNameParent.y + fullNameParent.height
        height: parent.height - fullName.height * 1.7
        width: parent.width

        Component.onCompleted: {
    //        console.log("Page.width: " + width);

            var objectValue = APIBridge.getObject();
            var i = 0;
            console.log(objectValue);
            fullName.text = objectValue[i++];

            var valueName = [
                        "Kraj",
                        "Miasto",
                        "Kod pocztowy",
                        "Ulica",
                        "Kapitał",
                        "KRS",
                        "NIP",
                        "REGON",
                        "WWW",
                        "E-mail",
                        "Firma",
                        "Forma prawna",
                        "Nazwa organu\nreprezentacji",
                        "Data\ndokonania wpisu",
                        "Cel\ndziałalności",
                        "Sposób\nreprezentacji",
                        "Data zawieszenia działalności",
                        "Data wznowienia działalności",
                        "Data rejestracji stowarzyszenia",
                        "Data wyrejestrowania przedsiębiorcy",
                        "Data wykreślenia stowarzyszenia",
                        "Oznaczenie sądu",
                        "Sygnatura akt"
                    ];

            while(i < objectValue.length && i < valueName.length + 1)
                listModel.append({
                                    nameID: valueName[i - 1],
                                    nameText: valueName[i - 1] + ": ",
                                    valueID: objectValue[i],
                                    valueText: objectValue[i++]
                                 });

//            fullName.text = object[i++];
//            countryValue.text = object[i++];
//            cityValue.text = object[i++];
//            postalCodeValue.text = object[i++];
//            streetValue.text = object[i++];
//            capitalValue.text = object[i++];
//            krsValue.text = object[i++];
//            nipValue.text = object[i++];
//            regonValue.text = object[i++];
//            wwwValue.text = object[i++];
//            emailValue.text = object[i++];
//            firmValue.text = object[i++];
//            formValue.text = object[i++];
//            representationValue.text = object[i++];
//            dateRegValue.text = object[i++];
//            actionPurposeValue.text = object[i++];
//            representationMethodValue.text = object[i++];
//            dateOperationsSuspensionsValue.text = object[i++];
//            dateOperationsResumptionValue.text = object[i++];
//            registrationDateValue.text = object[i++];
//            de_registrationDateValue.text = object[i++];
//            cancellationDateValue.text = object[i++];
//            courtSignValue.text = object[i++];
//            actSignatureValue.text = object[i++];

        }

        ListView {
            id: list
            anchors.fill: parent
            spacing: 3

            delegate: Item {
                width: parent.width
//                height: list.height * 0.06
                height: valueID.height > nameID.height ? valueID.height : nameID.height

                Text {
                    id: nameID
                    text: nameText
                    anchors.verticalCenter: parent.verticalCenter
                    x: parent.width * 0.02
                    font.letterSpacing: 0.6

                    font.pixelSize: page.font.pixelSize * 1.1
                    color: "#6666cc"

                    wrapMode: Text.WordWrap
                }

                Text {
                    id: valueID
                    text: valueText
                    anchors.verticalCenter: parent.verticalCenter
//                    x: nameID.x + nameID.width
                    x: nameID.x + nameID.contentWidth * 1.02
                    width: parent.width - nameID.x - nameID.width - parent.width * 0.04

                    font.pixelSize: page.font.pixelSize
                    color: "#6666cc"

                    wrapMode: Text.WordWrap
                }
            }

            model: ListModel {
                id: listModel
            }
        }
    }

    ItemDelegate {
        id: fullNameParent
        x: 0; y: 0
        width: parent.width
        height: fullName.height * 1.5

        Text {
            id: fullName
            anchors.verticalCenter: parent.verticalCenter
            x: parent.width * 0.02
            width: parent.width - parent.width * 0.04

            font.pixelSize: parent.font.pixelSize * 1.4
            color: "#6666cc"

            wrapMode: Text.WordWrap
        }

        background: Rectangle {
            color: "white"
        }
    }
}
