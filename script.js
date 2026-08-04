function updateClock() {
    const now = new Date();

    const year = now.getFullYear();
    const month = String(now.getMonth() + 1).padStart(2, '0');
    const day = String(now.getDate()).padStart(2, '0');

    const days = ['일', '월', '화', '수', '목', '금', '토'];
    const dayName = days[now.getDay()];

    const hours = String(now.getHours()).padStart(2, '0');
    const minutes = String(now.getMinutes()).padStart(2, '0');
    const seconds = String(now.getSeconds()).padStart(2, '0');

    const dateString = `${year}년 ${month}월 ${day}일 (${dayName})`;
    const timeString = `${hours}:${minutes}:${seconds}`;

    document.getElementById('date').textContent = dateString;
    document.getElementById('time').textContent = timeString;
}

// Initial call to display clock immediately
updateClock();

// Update every second
setInterval(updateClock, 1000);