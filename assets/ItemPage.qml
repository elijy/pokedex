import bb.cascades 1.2

Page {
    property alias name: titlebar.title
    property alias type: type_label.text 
    property alias hitpoints: hitpoints_label.text
    property alias attack: attack_label.text
    property alias defense: defense_label.text
    property alias specialAttack: specialAttack_label.text
    property alias specialDefense: specialDefense_label.text
    property alias speed: speed_label.text
    property alias height: height_label.text
    property alias weight: weight_label.text
    property alias total: total_label.text
    // "type" property of this screen is mapped to the text field of the UI element with the id of "type_label"
    // TODO: create other aliases that will be set from main.qml
    
    titleBar: TitleBar {
        id: titlebar
    }
    Container {
        Container { // Make a container to show pokemon type
            layout: StackLayout { // Lay out sub items left-to-right
                orientation: LayoutOrientation.LeftToRight
            }
            Label { 
                text: "Type: "
                textStyle.fontWeight: FontWeight.Bold
                textStyle.color: Color.DarkRed // Show this text
            } 
	        Label {
                id: type_label // Name this as type_label so that the property alias above can set the text property of this item
            } 
        }	
        Container {
            layout: StackLayout { // Lay out sub items left-to-right
                orientation: LayoutOrientation.LeftToRight
            }
            Label { 
                text: "Hit Points: "
                textStyle.fontWeight: FontWeight.Bold
                textStyle.color: Color.DarkRed // Show this text
            } 
            Label {
                id: hitpoints_label
            } 
        }
        Container {
            layout: StackLayout { // Lay out sub items left-to-right
                orientation: LayoutOrientation.LeftToRight
            }
            Label { 
                text: "Attack: "
                textStyle.fontWeight: FontWeight.Bold
                textStyle.color: Color.DarkRed // Show this text
            } 
            Label {
                id: attack_label
            } 
        }
        Container {
            layout: StackLayout { // Lay out sub items left-to-right
                orientation: LayoutOrientation.LeftToRight
            }
            Label { 
                text: "Defense: "
                textStyle.fontWeight: FontWeight.Bold
                textStyle.color: Color.DarkRed // Show this text
            } 
            Label {
                id: defense_label
            } 
        }
        Container {
            layout: StackLayout { // Lay out sub items left-to-right
                orientation: LayoutOrientation.LeftToRight
            }
            Label { 
                text: "Special Attack: "
                textStyle.fontWeight: FontWeight.Bold
                textStyle.color: Color.DarkRed // Show this text
            } 
            Label {
                id: specialAttack_label
            } 
        }
        Container {
            layout: StackLayout { // Lay out sub items left-to-right
                orientation: LayoutOrientation.LeftToRight
            }
            Label { 
                text: "Special Defense: "
                textStyle.fontWeight: FontWeight.Bold
                textStyle.color: Color.DarkRed // Show this text
            } 
            Label {
                id: specialDefense_label
            } 
        }
        Container {
            layout: StackLayout { // Lay out sub items left-to-right
                orientation: LayoutOrientation.LeftToRight
            }
            Label { 
                text: "Speed: "
                textStyle.fontWeight: FontWeight.Bold
                textStyle.color: Color.DarkRed // Show this text
            } 
            Label {
                id: speed_label
            } 
        }
        Container {
            layout: StackLayout { // Lay out sub items left-to-right
                orientation: LayoutOrientation.LeftToRight
            }
            Label { 
                text: "Height: "
                textStyle.fontWeight: FontWeight.Bold
                textStyle.color: Color.DarkRed // Show this text
            } 
            Label {
                id: height_label
            } 
        }
        Container {
            layout: StackLayout { // Lay out sub items left-to-right
                orientation: LayoutOrientation.LeftToRight
            }
            Label { 
                text: "Weight: "
                textStyle.fontWeight: FontWeight.Bold
                textStyle.color: Color.DarkRed // Show this text
            } 
            Label {
                id: weight_label
            } 
        }
        Container {
            layout: StackLayout { // Lay out sub items left-to-right
                orientation: LayoutOrientation.LeftToRight
            }
            Label { 
                text: "Base Experience: "
                textStyle.fontWeight: FontWeight.Bold
                textStyle.color: Color.DarkRed // Show this text
            } 
            Label {
                id: total_label
            } 
        }
    }	
}