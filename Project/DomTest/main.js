const helloBtn = document.getElementById('helloBtn');
//修改样式的dom操作
//实现类似于伪类:active的效果
helloBtn.addEventListener("mousedown",function(){
    helloBtn.classList.add('active');
});
helloBtn.addEventListener("mouseup",function(){
    helloBtn.classList.remove('active');
});
helloBtn.addEventListener("mouseleave",function(){
    helloBtn.classList.remove('active');
});
//添加标签元素的dom操作
const addCardBtn = document.getElementById('addCard');
const cardContainer = document.getElementById('cardContainer');
let  cardCount = 0;
function createCardElement(title, content){
    const card = document.createElement('div');
    const cardTitle = document.createElement('h3');
    const cardContent = document.createElement('p');
    card.classList.add('selfCard');
    cardTitle.textContent = title;
    cardContent.textContent = content;
    card.appendChild(cardTitle);
    card.appendChild(cardContent);
    return card;
}
function handleAddCard() {
    cardCount++;
    const newCard = createCardElement(`卡片 ${cardCount}`,`这是第 ${cardCount} 张动态创建的卡片。`);
    cardContainer.appendChild(newCard);
}

addCardBtn.addEventListener('click',handleAddCard);