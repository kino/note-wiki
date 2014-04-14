var TopNav = function(){
	var root="ctrip_html";
	var url = location.href;
	var subUrl = url.substr(url.indexOf(root)+root.length + 1);
	var levels = subUrl.split("/");
	levels[0] = "index";
	var length = levels.length;

	var titles = {
		"index":"首页",
		"bash":"Bash",
		"vim":"Vim",
		"java":"Java",
		"css":"Css",
		"nio":"Nio",
		"git":"Git"
	};
	var navContainer = $("#top-nav");
	$.each(levels,function(index,item){
		var count = length-index-1;
		var prefix = "";
		for(var i = 0; i < count; i++){
			prefix+="../";
		}
		if(item.indexOf(".html")<0){
			var title = titles[item];
			if(!title)title=item;
			$('<li><a href="'+prefix+item+'.html">'+ title +'</a></li>').appendTo(navContainer);
		}else{
			$('<li><span>'+document.title+'</span></li>').appendTo(navContainer);
		}
	});
}
$(document).ready(function(){
	new TopNav();
	var rootPath = $('#root_path').val();

	var brushes = {};
	var pres = $('pre');
	$.each(pres,function(index,item){
		var css = $(item).attr('class');
		if(css){
			var csses = css.split(' ');
			for(var i = 0; i < csses.length; i++){
				brushes[csses[i]] = 1;
			}
		}
	});
	for(prop in brushes){
	}

	SyntaxHighlighter.autoloader(
		  'bash  '+rootPath+'/js/sh/scripts/shBrushBash.js',
		  'java  '+rootPath+'/js/sh/scripts/shBrushJava.js',
		  'js javascript  '+rootPath+'/js/sh/scripts/shBrushJScript.js',
		  'c cpp  '+rootPath+'/js/sh/scripts/shBrushCpp.js',
		  'perl  '+rootPath+'/js/sh/scripts/shBrushPerl.js',
		  'xml  '+rootPath+'/js/sh/scripts/shBrushXml.js',
		  'css  '+rootPath+'/js/sh/scripts/shBrushCss.js'
		);
	 
	SyntaxHighlighter.all()
});
