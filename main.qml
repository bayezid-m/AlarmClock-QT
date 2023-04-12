import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15

Window {
    width: 640
    height: 480
    color:  "#fffacd"
    visible: true
    title: qsTr("Alarm Clock")
    FontLoader { id: webFont; source: "file:///E:/radioicon/digital-7.ttf" }
    Rectangle {
        anchors.verticalCenterOffset: -100
        anchors.horizontalCenterOffset: 0
        anchors.centerIn: parent;
        width: 350
        height: 120
        color: "#556b2f00"
        x: 50
        Row{
            anchors.verticalCenterOffset: -15
            anchors.horizontalCenterOffset: 0
            anchors.centerIn: parent;
            Text {
                id: txt_box
                text: ("14")
                font.family: webFont.name
                font.pointSize: 50
                anchors.verticalCenterOffset: 0
                anchors.horizontalCenterOffset: -60
                anchors.centerIn: parent
            }
            Text {
                id: txt_box2
                text: (":")
                font.family: webFont.name
                font.pointSize: 50
                anchors.verticalCenterOffset: 0
                anchors.horizontalCenterOffset: 0
                anchors.centerIn: parent
            }
            Text {
                id: txt_box3
                text: ("24")
                font.family: webFont.name
                font.pointSize: 50
                anchors.verticalCenterOffset: 0
                anchors.horizontalCenterOffset: 60
                anchors.centerIn: parent
            }
        }


        border.color: "black"
        border.width: 2

        Column{
            anchors.verticalCenterOffset: 0
            anchors.horizontalCenterOffset: -150
            anchors.centerIn: parent;
            Text {
                id: txt_box4
                text: ""
                font.pointSize: 12

            }

        }
        Text {
            id: txt_box9
            text: "5"
            font.family: webFont.name
            font.pointSize: 20
            anchors.verticalCenterOffset: 30
            anchors.horizontalCenterOffset: -15
            anchors.centerIn: parent;
            color: "black"
        }
        Text {
            id: txt_box11
            text: "/"
             font.family: webFont.name
            font.pointSize: 20
            anchors.verticalCenterOffset: 30
            anchors.horizontalCenterOffset: 0
            anchors.centerIn: parent;
            color: "black"
        }
        Text {
            id: txt_box10
            text: "4"
             font.family: webFont.name
            font.pointSize: 20
            anchors.verticalCenterOffset: 30
            anchors.horizontalCenterOffset: 15
            anchors.centerIn: parent;
            color: "black"
        }
        Column{
            anchors.verticalCenterOffset: 0
            anchors.horizontalCenterOffset: 150
            anchors.centerIn: parent;
            Text {
                id: txt_box6
                text: ""
                font.pointSize: 12
                anchors.verticalCenterOffset: -20
                anchors.horizontalCenterOffset: 0
                anchors.centerIn: parent
            }
            Text {
                id: txt_box7
                text: ""
                font.pointSize: 12
                anchors.verticalCenterOffset: 0
                anchors.horizontalCenterOffset: 0
                anchors.centerIn: parent
            }
            Text {
                id: txt_box8
                text: "FM"
                font.pointSize: 12
                anchors.verticalCenterOffset: 20
                anchors.horizontalCenterOffset: 0
                anchors.centerIn: parent
            }
        }
        Row{
            anchors.verticalCenterOffset: 100
            anchors.horizontalCenterOffset: 0
            anchors.centerIn: parent;
            spacing: 5

            Button{
                id: btn2
                text: "Set"
                font.pointSize: 12
                width: 100;
                height: 40;
                background: Rectangle {
                    color: btn2.pressed? "#556b2f" : "#b8860b";
                    border.color: "#00008b"
                    border.width: 3
                          radius: 4
                       }
                onClicked: {
                         myapp.func_btn_set()

                }
//                onReleased: {
//                    myapp.func_btn_unset()
//                    start = 0;
//                }
            }
            Button{
                id: btn4
                text: "Al"
                font.pointSize: 12
                width: 100;
                height: 40;
                background: Rectangle {
                    color: btn4.pressed? "#556b2f" : "#b8860b";
                    border.color: "#00008b"
                    border.width: 3
                          radius: 4
                       }
                onClicked:{
                    myapp.func_btn_al()
                }
            }
            Button{
                id: btn3
                text: "SNOOZE"
                font.pointSize: 12
                width: 100;
                height: 40;
                background: Rectangle {
                    color: btn3.pressed? "#556b2f" : "#b8860b";
                    border.color: "#00008b"
                    border.width: 3
                          radius: 4
                       }
                onClicked:{
                    myapp.func_btn_stop()
                }
            }

            Button{
                id: btn1
                text: "Up"
                font.pointSize: 12
                width: 100;
                height: 40;
                background: Rectangle {
                    color: btn1.pressed? "#556b2f" : "#b8860b";
                    border.color: "#00008b"
                    border.width: 3
                          radius: 4
                       }
                onClicked:{
                    myapp.func_btn_up()

                }
            }
            Button{
                id: btn5
                text: "Dn"
                font.pointSize: 12
                width: 100;
                height: 40;
                background: Rectangle {
                   color: btn5.pressed? "#556b2f" : "#b8860b";
                   border.color: "#00008b"
                   border.width: 3
                         radius: 4
                       }
                onClicked:{
                    myapp.func_btn_dwn()
                }
            }
        }
    }
    Connections
    {
        target:myapp
        ignoreUnknownSignals: true

        function onSendMess(text_box_str)
        {
            txt_box.text = text_box_str;
        }
        function onSendMess2(text_box_str2)
        {
            txt_box3.text = text_box_str2;
        }
        function onSendMess3(text_box_str3)
        {
            txt_box4.text = text_box_str3;
        }
        function onSendMess4(text_box_str4)
        {
            txt_box2.text = text_box_str4;
        }
        function onSendMess5(text_box_str5)
        {
            txt_box6.text = text_box_str5;
        }
        function onSendMess6(text_box_str6)
        {
            txt_box7.text = text_box_str6;
        }
        function onSendMess7(text_box_str7)
        {
            txt_box9.text = text_box_str7;
        }
        function onSendMess8(text_box_str8)
        {
            txt_box10.text = text_box_str8;
        }


    }


}
