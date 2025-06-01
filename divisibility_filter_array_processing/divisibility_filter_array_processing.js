//11.15.24
//More notes in html code

//FUNCTIONS
//make an array from given range
function arrayGen(N) {
    let a = [];
    for (i = 1; i <= N; i++) {
        a.push(i);
    }
    return a;
}

//uses the math lib 
function arrayShuffle(array) {
    for (i = array.length - 1; i > 0; i--) {
        let random = Math.floor(Math.random() * (i + 1));
        // Swap the elements in the array
        [array[i], array[random]] = [array[random], array[i]];
    }
    return array;
}

//collects first ten numbers from array var
function getFirst10(array) {
   let first10 = [];
    for (i = 0; i < 10; i++) {
        first10.push(array[i]);
    }
    return first10;
}

//if divisible by 2 return numbers
function divisibleBy2(array) {
    let result = [];
    for (i = 0; i < array.length; i++) {
        if (array[i] % 2 === 0) {
            result.push(array[i]);
        }
    }
    return result;
}

//if divisible by 5 return numbers
function divisibleBy5(array){
    let result = [];
    for (i = 0; i < array.length; i++) {
        if (array[i] % 5 === 0) {
            result.push(array[i]);
        }
    }
    return result;
}

//if divisible by 2 and 5 return numbers
function divisibleBy2And5(array) {
    let result = [];
    for (i = 0; i < array.length; i++) {
        if (array[i] % 2 === 0 && array[i] % 5 === 0) {
            result.push(array[i]);
        }
    }
    return result;
}

//START
var array = arrayGen(100);
array = arrayShuffle(array);

var random10 = getFirst10(array);

var divBy2 = divisibleBy2(random10);
var divBy5 = divisibleBy5(random10);
var divBy2And5 = divisibleBy2And5(random10);

console.log("Random 10 Numbers:", random10);
console.log("Divisible by 2:", divBy2);
console.log("Divisible by 5:", divBy5);
console.log("Divisible by 2 and 5:", divBy2And5);