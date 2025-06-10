import QtQuick
import QtQuick.Controls 2.15
import QtQuick.Layouts
import IpCalculator 1.0
ApplicationWindow{
    id: mainWIndow
    width: 640
    height: 480
    visible:  true
    title: qsTr("IP Calcualtor");

    property var ipCalculator: IpCalculator{}//создание экземпляра класса IpCalculator

    //------------Цветовая Палитра---------//
    property color colorBgStart: "#2c3e50"     // Темно-синий
    property color colorBgEnd: "#34495e"       // Серо-синий
    property color colorFrameBg: "#ecf0f1"     // Очень светлый серый для рамки
    property color colorText: "#2c3e50"        // Темный текст на светлом фоне
    property color colorInputBg: "#ffffff"     // Белый фон полей ввода
    property color colorInputBorder: "#bdc3c7" // Серая рамка для полей

    //----Фон Окна
    background: Rectangle {
            gradient: Gradient {
                GradientStop { position: 0.0; color: mainWIndow.colorBgStart }
                GradientStop { position: 1.0; color: mainWIndow.colorBgEnd }
            }
        }

    // --- "Карточка" для основного контента ---
    Frame {
        anchors.centerIn: parent
        width: parent.width * 0.8
        background: Rectangle{
            color:mainWIndow.colorFrameBg
            radius:  8
            }

        ColumnLayout{
            anchors.fill: parent
            anchors.margins: 10
            Label{
                text: qsTr("IP Address");
            }
            //Фon


            TextField{
                id: ipAddressFieldId
                Layout.fillWidth: true
                text: "192.168.1.1"
                validator: RegularExpressionValidator {
                    regularExpression:  /^(([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])\.){3}([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])$/
                    }
                onEditingFinished: {
                    ipCalculator.ipAddress = text;
                    ipCalculator.calculateInfo();
                    }
                //102.12.12.3
                }
            Label{
                text: qsTr("Subnet Mask");
            }
            TextField{
                id: subnetMaskField
                Layout.fillWidth: true
                text: "255.255.255.0"
                validator: RegularExpressionValidator{
                    regularExpression: /^(([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])\.){3}([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])$/
                }
                onEditingFinished: {
                    ipCalculator.subnetMask = text;
                    ipCalculator.calculateInfo();
                    prefixLengthField.text = ipCalculator.prefixLength.toString();
                }
            }

            Label{
                text: qsTr("Prefix Lengths");
                }
            TextField{
                id:prefixLengthField
                Layout.fillWidth: true
                text: "24"
                validator: IntValidator {bottom: 0; top: 32}
                onEditingFinished: {
                    ipCalculator.prefixLength = parseInt(text);
                    ipCalculator.calculateInfo();
                     subnetMaskField.text = ipCalculator.subnetMask;
                    }
                }
            Label{
                text: qsTr("Info");
                }
            TextEdit{
                id: infoText
                Layout.fillWidth: true
                Layout.fillHeight: true
                readOnly: true
                text: ipCalculator.info
                color: mainWIndow.colorTextss
                }


            Connections{
                target:  ipCalculator
                onInfoChanged: {
                   infoText.text = ipCalculator.info;
                }
            }
        }
    }
}
// [QML]                                    [C++ IpCalculator]
// Пользователь вводит в поле -> ipCalculator.subnetMask = "255.255.0.0"
//                                      |
//                                      v
//                            (Срабатывает `WRITE setSubnetMask`)
//                            void setSubnetMask("255.255.0.0") {
//                                m_subnetMask = "255.255.0.0";
//                                emit subnetMaskChanged();  <-- "ВЫСТРЕЛ"
//                            }
//                                      |
//                                      v
// (Движок Qt/QML слышит сигнал `subnetMaskChanged`)
//          |
//          |---> (1) Перевычислить `Label.text`
//          |       - Вызвать `READ subnetMask()` -> получить "255.255.0.0"
//          |       - Обновить Label.text
//          |
//          |---> (2) Перевычислить `Rectangle.color`
//          |       - Вызвать `READ subnetMask()` -> получить "255.255.0.0"
//          |       - Обновить Rectangle.color
//          |
//          |---> (3) Выполнить `onSubnetMaskChanged`
//                  - Вызвать `READ subnetMask()` -> получить "255.255.0.0"
//                  - Выполнить код внутри обработчика

