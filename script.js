// create Variable
var seconds = 00;
var tens = 00;
var steps = 00;
var count_step = 0;
var old_steps = 0;
var old_seconds = 00;
var count = 0;
// get Value from HTML to Variable
var appendTens = document.getElementById("tens");
var appendSeconds = document.getElementById("seconds");
var appendSteps = document.getElementById("steps");
var appendCountSteps = document.getElementById("count-steps");

var buttonStart = document.getElementById("button-Start");
var buttonStop = document.getElementById("button-Stop");
var buttonReset = document.getElementById("button-Reset");
var interval;
// to store timer values

// Step/Seconds
var buttonUp = document.getElementById("button-Up");
var buttonDown = document.getElementById("button-Down");

// Steps
var buttonPlus = document.getElementById("button-Plus");
var buttonMinus = document.getElementById("button-Minus");

// Left foot
var LB = document.getElementById('sp_LB');
var LG = document.getElementById('sp_LG');

//Right foot
var RB = document.getElementById('sp_RB');
var RG = document.getElementById('sp_RG');

// This function show befoer start
document.getElementById('sp_LG').style.display = 'none';
document.getElementById('sp_LB').style.display = '';
document.getElementById('sp_RG').style.display = 'none';
document.getElementById('sp_RB').style.display = '';

// this functions will run back when click on start
function startTimer() {
    tens--;
    if (tens > 9) {
        appendTens.innerHTML = tens;
    }
    if (tens < 9) {
        appendTens.innerHTML = tens;
    }
    if (tens <= 0) {
        seconds--;
        appendSeconds.innerHTML = seconds;

        if (seconds != 00) {
            tens = 99;
            appendTens.innerHTML = "9" + 9;

        } else if (seconds == 0) {
            if (steps > 0) {
                steps--;
                seconds = old_seconds;
                appendSteps.innerHTML = steps;
                appendSeconds.innerHTML = seconds;
                clearInterval(interval);
                tens = 99;
                appendTens.innerHTML = "9" + 9;
                interval = setInterval(startTimer, 10);
                if (count_step == old_steps) {
                    count_step = 0;
                    appendCountSteps.innerHTML = count_step;
                }
                if (count_step != old_steps) {
                    count_step++;
                    appendCountSteps.innerHTML = count_step;
                    if (count == 0 || count == 2) {
                        count = 1;
                    } else { count = 2; }
                }
            } else if (steps == 0) {
                clearInterval(interval);
                tens = "00";
                appendTens.innerHTML = tens;
            }
        }
    }
    if (seconds <= 9) {
        appendSeconds.innerHTML = "0" + seconds;
    }
    if (seconds == 0) {
        clearInterval(interval);
    }
    if (count == 1) {
        document.getElementById('sp_LG').style.display = '';
        document.getElementById('sp_LB').style.display = 'none';
        document.getElementById('sp_RG').style.display = 'none';
        document.getElementById('sp_RB').style.display = '';
    } else if (count == 2) {
        document.getElementById('sp_LG').style.display = 'none';
        document.getElementById('sp_LB').style.display = '';
        document.getElementById('sp_RG').style.display = '';
        document.getElementById('sp_RB').style.display = 'none';
    }
}

buttonUp.onclick = function () {
    seconds++;
    appendSeconds.innerHTML = seconds;
}

buttonDown.onclick = function () {
    seconds--;
    appendSeconds.innerHTML = seconds;
}

buttonPlus.onclick = function () {
    steps++;
    appendSteps.innerHTML = steps;
}

buttonMinus.onclick = function () {
    steps--;
    appendSteps.innerHTML = steps;
}

buttonStart.onclick = function () {
    if (seconds != 0 || tens != 0) {
        old_steps = steps;
        old_seconds = seconds;
        interval = setInterval(startTimer, 10);
    }
};

buttonStop.onclick = function () {
    clearInterval(interval);
};

buttonReset.onclick = function () {
    clearInterval(interval);
    tens = "00";
    seconds = "00";
    steps = "0";
    count_step = "0";
    appendCountSteps.innerHTML = 0;
    appendSteps.innerHTML = 0;
    appendSeconds.innerHTML = seconds;
    appendTens.innerHTML = tens;
    document.getElementById('sp_LG').style.display = 'none';
    document.getElementById('sp_LB').style.display = '';
    document.getElementById('sp_RG').style.display = 'none';
    document.getElementById('sp_RB').style.display = '';
    count = 0;
}