async function loadContent(filePath) {
    const response = await fetch(filePath);
    const markdown = await response.text();
    const mainContent = document.querySelector('.main-content');
    mainContent.innerHTML = marked(markdown);
}

document.addEventListener('DOMContentLoaded', () => {
    document.querySelectorAll('.sidebar-links a').forEach(link => {
        link.addEventListener('click', (e) => {
            e.preventDefault();
            const filePath = e.target.getAttribute('data-file');
            loadContent(filePath);
        });
    });
});
