<style>
	code {
		font-family: 'Courier New', Courier, monospace;
		color: #d63384;
	}
</style>

# Toolbox

<br>

For this project, we used several tools, let's discover them!

<br>

## GNU gprof

---

<br>

The first tool we used was [gprof](https://en.wikipedia.org/wiki/Gprof). It's a powerful profiler (performance analysis) for Unix applications. It used a hybrid of instrumentation and sampling and was created as an extended version of the older `prof` tool. Unlike prof, gprof is capable of limited call graph collecting and printing.

<br>

### How it works

<br>

The use is pretty simple. First, you need to add the `-pg` option in your compilation flags to gather caller-function data. A call to the monitor function `mcount` is inserted before each function call.

<br>

Then, you need to run the program, test it and exit.

<br>

Sampling data is saved in a `gmon.out` file just before the program exits, and can be analyzed with the `gprof` command-line tool.

<br>

Here's the command-line to test it with our program:

<br>

`gprof *executable-file* gmon.out > *outfile*`

<br>

And here it is! You get a file with all the data needed to analyze your program's performances.

<br>

Here's an example of an output for a small program:

<br>

<div style="display: flex; flex-direction: row; justify-content: center;">
	<img src="/gomoku/outfile.png" width="497" height="304">
</div>

<br>

For more details, see the official [GNU gprof manual](https://ftp.gnu.org/old-gnu/Manuals/gprof-2.9.1/html_mono/gprof.html).
