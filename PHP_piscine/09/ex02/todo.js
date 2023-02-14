var cookieStash = Array;

function runPrompt() {
	let task = prompt("New task:");
	if (task !== "" && task !== null) {
		addElement(task);
	}
}

function addElement(task) {
	// Create a "li" element:
	const newNode = document.createElement("div");
	newNode.onclick = function () {
		var sure = confirm("Are you sure?");
		if (sure) {
			this.parentElement.removeChild(this);
			document.cookie = task + "=" + task +
				";expires=Thu, 01 Jan 1970 00:00:01 GMT";
		}
	}
	// Create a text node:
	const textNode = document.createTextNode(task);
	// Append text node to "li" element:
	newNode.appendChild(textNode);

	// Insert before existing child:
	const list = document.getElementById("ft_list");
	list.insertBefore(newNode, list.children[0]);
	document.cookie = task + "=" + task;
}

function readCookie() {
		if (document.cookie != "")
		{
			cookieStash = document.cookie.split(';');
			var i = 0;
			while (cookieStash[i])
			{

				addElement(cookieStash[i].split('=')[1]);
				i++;
			}
		}
	}

