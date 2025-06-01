//11.22.24

// Function for setting the bed sizes based on the room type
function setBedSizes() {
    var roomType;
    var radios = document.getElementsByName("rtype"); // Get all radio buttons with name="rtype"
        for (var i = 0; i < radios.length; i++) {
            if (radios[i].checked) {
            roomType = radios[i].id; // gets the ID of the checked radio button
            break; //Exit the loop if checked radio button is found
    }
}
/*
getElementsByName, method
W3Schools
*/


//Enable all bed sizes by default
    document.getElementById("bssingle").disabled = false;
    document.getElementById("bsdouble").disabled = false;
    document.getElementById("bsqueen").disabled = false;
    document.getElementById("bsking").disabled = false;


//Disable all bed sizes depending on roomtype

// Disables for livingroom and office
    if (roomType === "rtliving"||roomType === "rtoffice") {
        document.getElementById("bssingle").disabled = true;
        document.getElementById("bsdouble").disabled = true;
        document.getElementById("bsqueen").disabled = true;
        document.getElementById("bsking").disabled = true;

// Disables the queen and king sizes for children’s room
    } else if (roomType === "rtchildren") {
        document.getElementById("bsqueen").disabled = true;
        document.getElementById("bsking").disabled = true;
    }
}
/*
remember it"s not elif, it"s else if

using .disabled property
W3Schools
*/


// Function for DELIVERY OPTIONS

function isDelivered() {
    var deliveryOption = document.getElementById("deliveryYes").checked;

    var address = document.getElementById("daddress");
    var date = document.getElementById("ddate");
    var time = document.getElementById("dtime");


    if (deliveryOption) {
        address.disabled = false;
        date.disabled = false;
        time.disabled = false;
// Enable delivery inputs because deliveryOption is checked

    } else {

        address.disabled = true;
        date.disabled = true;
        time.disabled = true;
// Disable delivery inputs because they picked third-party pickup thing

    }

}
/*
.checked property
W3Schools
*/



// Function to check if the DATE is indeed valid

function allowedDate() {
    var dateInput = document.getElementById("ddate").value;
    var today = new Date();
	
    var selectedDate = document.getElementById("ddate").value; //string
	var selectedDateTimestamp = Date.parse(selectedDate); //timestamp

/*
testing:
console.log(today);
console.log(selectedDate);

yup, dateInput needs to be inside new Date so its a Date obj

.value property to get value of ddate
new Date() to get the current date and time
W3Schools
*/


    if (selectedDateTimestamp <= Date.parse(today)) {
        alert("please select a future date from now"); //added an alert
        document.getElementById("ddate").value = ""; // Clears if an invalid date
    }
}



// check if 9AM and 6PM
function allowedTime() {
    var timeInput = document.getElementById("dtime").value;

//need to find a way to split the time to compare
    var timeParts = timeInput.split(":");
    var hour = parseInt(timeParts[0]);

/*
testings
console.log(timeInput) example 11:31
console.log(timeParts) example ["11","31"]
console.log(hour)

timeParts[0] gets the first value in the array, in this case 11
parseInt() function makes it into an int for comparisons
so 11 becomes an integer now

hour 18 is 6pm of course
*/

    if (hour < 9 || hour >= 18) {
        alert("Please select a time between 9AM and 6PM (office hours)"); //added an alert
        document.getElementById("dtime").value = ""; // Clear if invalid time
    }
}


// COSTING AND SUMMARY

function submitClicked() {

//setting variables
    var name = document.getElementById("name").value;
    var mobile = document.getElementById("mnum").value;
    var email = document.getElementById("email").value;
    var occupants = document.getElementById("tiers").value;


    //Room type
	var roomType = "";
	var roomInputs = document.querySelectorAll("input[name='rtype']");
	for (var i = 0; i < roomInputs.length; i++) {
		if (roomInputs[i].checked) {
			roomType = roomInputs[i].nextElementSibling.textContent; //iterate
			break;
		}
	}

/*
console.log(roomType);
console.log(roomInputs);

.length

.querySelectorAll property method returns all elements that matches a CSS selector(s)
need this to get the elements with condition

.nextElementSibling returns the next element in the same tree level.
to get the next element

.textContent property sets or returns the text content of the specified node, and all its descendants.
to extract the text from it

W3Schools
*/

    //Bed size
	var bedSize = "None";
	var bedSizeInput = null;
	var bedInputs = document.querySelectorAll("input[name='bsize']");
	
	for (var i = 0; i < bedInputs.length; i++) {
		if (bedInputs[i].checked) {
			bedSize = bedInputs[i].nextElementSibling.textContent;
			bedSizeInput = bedInputs[i];
			break;
		}
	}
	
	var bedCost;
	if (bedSizeInput) {
		bedCost = parseInt(bedSizeInput.value);
	} else {
		bedCost = 0;
	}

/*
bedSize for the summary
bedSizeInput to get the bedCost
*/

	//Cabinets
	var cabinet = "None";
	var cabinetInput = null;
	var cabinetInputs = document.querySelectorAll("input[name='cabinets']");
	for (var i = 0; i < cabinetInputs.length; i++) {
		if (cabinetInputs[i].checked) {
			cabinet = cabinetInputs[i].nextElementSibling.textContent;
			cabinetInput = cabinetInputs[i];
			break;
		}
	}

	var cabinetCost;
	if (cabinetInput) {
		cabinetCost = parseInt(cabinetInput.value);
	} else {
		cabinetCost = 0;
	}


    //Tables
	var tableCost = 0;
	var tableInputs = document.querySelectorAll("input[name='tables']");
	for (var i = 0; i < tableInputs.length; i++) {
		if (tableInputs[i].checked) {
			tableCost += parseInt(tableInputs[i].value);
		}
	}
	
/*
for tables, since its a textbox, multiple items can be selected so you have to use parseInt convert and .value to collect the total cost of all the tables selected
*/
	//TABLE DISCOUNTS

//0.9 is better than tableCost - tableCost/10
	if (tableInputs.length === 2) {
		tableCost *= 0.9; // 10% discount
		
	} else if (tableInputs.length === 3) {
		tableCost *= 0.85; // 15% discount
		
	} else if (tableInputs.length === 4) {
		tableCost *= 0.75; // 25% discount
	}

	var tableLabels = [];
	for (var i = 0; i < tableInputs.length; i++) {
		if (tableInputs[i].checked) {
			tableLabels.push(tableInputs[i].nextElementSibling.textContent);
		}
	}

/*
tableLabels gets tables that are checked and puts them in an array for display
*/

    //Decorative additions
	var decoInputs = document.querySelectorAll("input[name='decorative']");
	var decoCost = 0;
	for (var i = 0; i < decoInputs.length; i++) {
		if (decoInputs[i].checked) {
			decoCost += parseInt(decoInputs[i].value);
		}
	}

	var decoLabels = [];
	for (var i = 0; i < decoInputs.length; i++) {
		if (decoInputs[i].checked) {
			decoLabels.push(decoInputs[i].nextElementSibling.textContent);
		}
	}


    //Room size
	var roomSizeMultiplier = parseFloat(document.getElementById("rsize").value);
	
	var roomSizeText = "";
		if (roomSizeMultiplier === 1) {
		roomSizeText = "Small";
		} else if (roomSizeMultiplier === 1.25) {
		roomSizeText = "Medium";
		} else if (roomSizeMultiplier === 1.5) {
		roomSizeText = "Large";
		} else if (roomSizeMultiplier === 2) {
		roomSizeText = "Extra Large";
	}
/*
roomSizeInput to get element
roomSize to get text

used parseFloat because multiplier value has decimals
*/

    // Delivery cost
	var deliveryCost = 0;
	var deliveryInput = document.getElementById("deliveryYes");

	if (deliveryInput.checked) {
		deliveryCost = 1000;  // Set cost to 1000 if the input is checked
	}

    // Calculate the total cost using formula
    var room_setup = ((bedCost + cabinetCost + tableCost + decoCost) * roomSizeMultiplier) + deliveryCost;

    // Show summary
    alert(`
[Customer Information]
Name: ${name}
Mobile number: ${mobile}
Email: ${email}

[ITEA Room Setup Details]
Number of occupants: ${occupants}
Room type: ${roomType}
Bed size: ${bedSize}
Cabinets: ${cabinet}
Tables: ${tableLabels}

Decorative Additions: ${decoLabels}
Room Size: ${roomSizeText}

Total cost of room setup: ${room_setup.toFixed(2)} PHP
    `);
}
/*
using string interpolation ${}

.toFixed() method rounds the string to a specified number of decimals.
W3Schools
*/

//Function to reset the form to its default state
	function resetRadio() {
		document.getElementById("rtbedroom").checked = true;
		setBedSizes();
		isDelivered();
	}