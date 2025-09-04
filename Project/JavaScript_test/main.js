const card = document.getElementById('card');
const toggleBtn = document.getElementById('toggleBtn');
const output = document.getElementById('counter');
const gettimeBtn = document.getElementById('gettimeBtn');
const timeoutput = document.getElementById('date');
const submitBtn = document.getElementById('submitBtn');
const guessNumberhint = document.getElementById('hint');
const numberinput = document.getElementById('numberinput');
const guessCount = document.getElementById('guessCount')

let count = 0;

function handleClick(){
    card.classList.toggle('dark');
    card.classList.toggle('light');
    count++;
    output.textContent = '已点击 ' + count + ' 次';
}

toggleBtn.addEventListener('click', handleClick);

/*
window.onload=function(){
    window.open("adv.html");
}
*/

function displayTime(){
    const date = new Date();
    const year = String(date.getFullYear()).padStart(2, '0');
    const month = String(date.getMonth()+1).padStart(2, '0');
    const day = String(date.getDate()).padStart(2, '0');
    const hh = String(date.getHours()).padStart(2, '0');
    const mm = String(date.getMinutes()).padStart(2, '0');
    const ss = String(date.getSeconds()).padStart(2, '0');
    return `${year}年${month}月${day}日  ${hh}:${mm}:${ss}`;
}
setInterval(() => {timeoutput.textContent = displayTime();},1000)

function handleTimeChange(){
    timeoutput.textContent = displayTime();
}
gettimeBtn.addEventListener('click', handleTimeChange);

function createNumber(){
    const num = Math.round(Math.random()*100 + 1);
    return Number(num);
}

const n =createNumber();
let guessCountTime = 0;
function handleSubmit(){
    guessCountTime++;
    const output = numberinput.value;
    if (output > n){
        guessNumberhint.textContent = "猜大了";
    }else if (output < n){
        guessNumberhint.textContent = "猜小了";
    }else {
        guessNumberhint.textContent = "猜对了!!!";
        numberinput.remove()
        submitBtn.remove()
    }
    guessCount.textContent = "你猜了"+guessCountTime+"次"
}
submitBtn.addEventListener('click', handleSubmit)