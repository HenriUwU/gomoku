async function loadContent(filePath) {
	try {
		const response = await fetch(filePath);
		if (!response.ok) {
			throw new Error(`HTTP error! status: ${response.status}`);
		}
		const markdown = await response.text();
		const mainContent = document.querySelector('.main-content');
		mainContent.innerHTML = marked(markdown);

		attachEventListeners();  
	} catch (error) {
		console.error('Error loading content:', error);
	}
}

function attachEventListeners() {
	document.querySelectorAll('.sidebar-header a, .sidebar-links a, .main-content ol li a').forEach(link => {
		link.addEventListener('click', (e) => {
			e.preventDefault();
			const anchor = e.target.closest('a');
			const filePath = anchor.getAttribute('data-file');
			if (filePath) {
				loadContent(filePath);
			} else {
				console.error('No data-file attribute found on the clicked element.');
			}
		});
	});
}

document.addEventListener('DOMContentLoaded', () => {
	attachEventListeners();
});
