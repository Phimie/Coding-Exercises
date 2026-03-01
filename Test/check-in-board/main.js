const userInput = document.querySelector('input[name="username"]');
const btn       = document.querySelector('button');
const listBox   = document.getElementById('list');

btn.addEventListener('click', () => {
    const name = userInput.value.trim();
    if (!name) return;
    const time = new Date().toLocaleString();
    listBox.innerHTML = `<li><strong>${name}</strong> · ${time}</li>`;
    userInput.value = '';
    userInput.focus();
});