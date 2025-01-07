<style>
	code {
		font-family: 'Courier New', Courier, monospace;
		color: #d63384;
	}
</style>

# Documentation

<br>

For this bonus, we decide to use [Astro](https://astro.build/), a JavaScript web framework, to create a little local and static website. In fact, this website.

<br>

## Principle

---

<br>

Astro provides powerful Markdown and MDX support, making it ideal for content-heavy websites like blogs and documentation. With its built-in Markdown capabilities, you can easily create static pages while seamlessly integrating dynamic components using MDX, which allows embedding JavaScript framework components (e.g., React, Vue) directly into your Markdown content. This combination enables rich, interactive content with minimal effort. Additionally, Astro optimizes for performance by shipping only the necessary HTML and CSS by default, and only hydrating JavaScript where required, making it a highly efficient framework for content-first websites.

<br>

## How it works

---

<br>

First, you'll need to install the latest versions of these dependencies: `nvm`, `Node.js` and `npm`.

<br>

Then, go to the `/doc` directory and run the `npm run dev` command.

<br>

And here it is! The documentation is now available at `http://localhost:4321/gomoku`.