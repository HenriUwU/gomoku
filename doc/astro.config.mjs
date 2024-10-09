import { defineConfig } from 'astro/config'
import markdownIntegration from '@astropub/md'

// https://astro.build/config
export default defineConfig({
    site: 'https://astronaut.github.io',
    base: 'gomoku',
    integrations: [
        markdownIntegration(),
    ],
        markdown: {
        remarkPlugins: [],
        rehypePlugins: [],
        syntaxHighlight: 'shiki',
        syntaxHighlight: 'prism'
    }
});
