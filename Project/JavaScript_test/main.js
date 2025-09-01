const card   = document.getElementById('card');
const btn    = document.getElementById('toggleBtn');
const output = document.getElementById('counter');

let count = 0;

function handleClick() {
  card.classList.toggle('dark');
  card.classList.toggle('light');
  count++;
  output.textContent = '已点击 ' + count + ' 次';
}


btn.addEventListener('click', handleClick)  //这里不能使用handleClick(),加了括号会立即执行函数,不加传入的是这个函数
