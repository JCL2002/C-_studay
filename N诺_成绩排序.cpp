<!DOCTYPE html>
<!-- saved from url=(0048)http://noobdream.com/DreamJudge/Issue/page/1151/ -->
<html lang="en"><head><meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    
    <meta name="referrer" content="never">
    <meta http-equiv="X-UA-Compatible" content="IE=Edge,chrome=1"><!-- 兼容渲染 -->
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
    <title>
	1151 - 成绩排序
</title>
    <link rel="shortcut icon" href="http://noobdream.com/static/image/fav.png">
    <!-- Bootstrap CSS -->
    <link rel="stylesheet" href="./N诺_成绩排序_files/bootstrap.min.v4.0.0.css">
    <link rel="stylesheet" href="./N诺_成绩排序_files/fontawesome.v5.8.0.css">
<link rel="stylesheet" href="./N诺_成绩排序_files/font-awesome.min.css">
    <link rel="stylesheet" href="./N诺_成绩排序_files/github.css">

    
    <script src="./N诺_成绩排序_files/jquery.slim.min.3.2.1.js.下载"></script>
    <script src="./N诺_成绩排序_files/popper.min.1.12.9.js.下载"></script>
    <script src="./N诺_成绩排序_files/bootstrap.min.4.0.js.下载"></script>
    <!-- Bootstrap core CSS -->
    <!--开头这里的样式为默认的风格，可以根据自己的喜好更换风格-->
    <!--我的高亮效果是zenburn-->
    <link rel="stylesheet" href="./N诺_成绩排序_files/xcode.css">
    <script src="./N诺_成绩排序_files/highlight.pack.js.下载"></script>
    <script>hljs.initHighlightingOnLoad();</script>

    <link rel="stylesheet" type="text/css" href="./N诺_成绩排序_files/right_bar_style.css"> 
    <script type="text/javascript" src="./N诺_成绩排序_files/jquery.min.js.下载"></script>

    <style>
        html {
            font-size: 14px;
            width: 100%;
        }
        body{
            padding: 0;
            min-width:1200px;
            min-height:100%;
            position:relative;
	    font-size:14px;
            font-family: Full-Width-Quoration-Marks,-apple-system,BlinkMacSystemFont,"Segoe UI",Roboto,"Helvetica Neue",Helvetica,"PingFang SC","Hiragino Sans GB","Microsoft YaHei",SimSun,FontAwesome,sans-serif;
        }
        nav a{ font-family: Full-Width-Quoration-Marks,-apple-system,BlinkMacSystemFont,"Segoe UI",Roboto,"Helvetica Neue",Helvetica,"PingFang SC","Hiragino Sans GB","Microsoft YaHei",SimSun,FontAwesome,sans-serif;
            font-weight: 400;
            font-size: 18px;
            float: left;
            margin:0 auto;
            }
        .dropdown-toggle::after{display: none;}
        a{
            text-decoration: none!important;
        }
div img{
     transition: all 0.6s;             
 }   
/*
div img:hover{ 
     transform: scale(1.05);  
}
*/
.btn:focus,.btn:active:focus,.btn.active:focus,.btn.focus,.btn:active.focus,.btn.active.focus { 
                       outline: none;   
                        border-color: transparent;  
                        box-shadow:none;
                       /*background:#77bc1f;*/
                       color:#fff;
                   }

    </style>
<style>
.shadow-sm{box-shadow: 0 .125rem .25rem rgba(0,0,0,.075)!important;}
        .nav-right nav a{
            font-size: 16px;
            color: #555;
            display: flex;
            align-items: center;
            justify-content:center;
            margin-right: 10px;
            height: 50px;
            box-sizing: border-box;
            text-decoration: none;
        }
        .nav-right nav a:hover{
            color: #1E90FF;
        }
        .nav-right nav a.active{
            min-width: 80px;
            height: atuo;
            border-bottom: 2px solid #1E90FF;
            color: #1E90FF;
        }
        .nav-left img{
            position: absolute;
            margin-left:0%;
            width: 90px;
            right:0%;
            padding-top:2px;
        }
        .nav-body{
            height: 50px!important;
        }
</style>
    <script>
        function logout() {
            $('#logout').submit();}
    </script>
    <!-- Custom styles for this template -->
    
<link rel="stylesheet" href="./N诺_成绩排序_files/font-awesome.min.css">
	<link href="./N诺_成绩排序_files/base16-dark.css" rel="stylesheet">
	<link href="./N诺_成绩排序_files/codemirror.css" rel="stylesheet">
	<script src="./N诺_成绩排序_files/codemirror.js.下载"></script>
	<script src="./N诺_成绩排序_files/clike.js.下载"></script>
	<script src="./N诺_成绩排序_files/python.js.下载"></script>
    <script type="text/javascript" src="./N诺_成绩排序_files/jquery.min.js.下载"></script>

	<style>
body{
font-size:16px;
}
		p{
			font-size: 14px;
			font-weight: 500;
		}
		pre{
			font-family: Courier,'Courier New',monospace;
                        font-size: 14px;
                        font-weight: 500;
                        padding: 10px 0 10px 10px;
                        margin: .1em 0;
			background:#fafafa;
                        border-left:2px solid #3498db;
		}
		article{
			margin-left: 0.75em;
		}
		h5{
			padding: 0.6em;
			border-bottom: 1px solid rgba(0, 0, 0, 0.1);
		}
		h6{
			margin-left: 0.8em;
			color: #515151;
		}
		.bttom-border{
			border-bottom: 1px solid rgba(200, 200, 100, 0.1);
		}
		.up-btn{
			height:12px;width:100%;background:#3d444c;text-align:center;

		}
		.up-btn .fas{color: #fff;font-size: 18px;background: #232c31;padding: 2px 8px 0 8px;line-height: 12px;vertical-align:top;display: inline-block;}
 		.up-btn .fas:hover{color:#08c;cursor:pointer;}
		.stu-box{
			width: 100%;
			height: 0;
			transition: 0.4s;
			background: #3d444c;
			margin-top: 0.1em;
		}
		.reset-btn{
			cursor: pointer;
			transition: 0.2s;
			user-select:none;
		}
		.reset-btn:active{
			font-weight: 700;
		}
		.font-size-18{
			font-size: 18px!important;
		}
		.font-size-19{
			font-size: 19px!important;
		}
		.font-size-24{
			font-size: 24px!important;
		}
		.font-size-32{
			font-size: 32px!important;
		}

	</style>
        <style type="text/css">
	.OjInfo {
	    background: #f8f9fa;
	    padding: 10px;
	    border-radius: 6px;
	    overflow: hidden;
	    font-family: Full-Width-Quoration-Marks,-apple-system,BlinkMacSystemFont,"Segoe UI",Roboto,"Helvetica Neue",Helvetica,"PingFang SC","Hiragino Sans GB","Microsoft YaHei",SimSun,FontAwesome,sans-serif;
	}
	</style>

</head>


<body style="background:url(/static/image/bg_pic_1.jpg);background-attachment:fixed;">

<div class="d-flex flex-row mb-1 bg-white border-bottom shadow-sm nav-body" style="margin-bottom:0;">
    <div class="col-1 nav-left" style="margin-left:0%;float:left;">
        <img src="./N诺_成绩排序_files/logo.png" style="cursor:pointer;" alt="NoobDream" onclick="window.location.href=&#39;/&#39;">
    </div>
    <div class="nav-right d-flex flex-row align-items-center justify-content-between col-10" style="min-width:975px;">
        <nav class="my-2 my-md-0 mr-md-3 ">
            <a class="p-2 ">&nbsp;&nbsp;</a>
            <a class="p-2 " href="http://noobdream.com/DreamJudge/Contest/index_judge/">DreamJudge</a>
            <a class="p-2 " href="http://noobdream.com/DreamJudge/Contest/match/">比赛</a>
            <a class="p-2 active" href="http://noobdream.com/DreamJudge/Issue/page/0/">题库</a>
            <a class="p-2 " href="http://noobdream.com/DreamJudge/Issue/problem_status/">提交状态</a>
            <a class="p-2" href="http://noobdream.com/Major/school_show/">历年真题</a>
            <a class="p-2 " href="http://noobdream.com/users/rank/">Rating排行榜</a>
        </nav>
        
            <div class="row">
<div class="tips-calendar_wrap" onclick="window.location.href=&#39;/users/info/20572/&#39;">
成为N诺er的第0天 <i class="fa fa-angle-right" style="margin-right:5px;font-size:14px;font-weight:bold;"></i>
</div>
<style>
.tips-calendar_wrap {
    background: rgba(250,142,87,.1);
    border: 1px solid rgba(250,142,87,.43);
    border-radius: 14px;
    padding: 5px 12px 5px 16px;
    font-size: 12px;
    color: #fa8e57;
    text-align: center;
    margin-right: 32px;
    margin-left: 12px;
    margin-top:4px;
    cursor: pointer;
    height:30px;
}
</style>
                <a class="avatar" style="border-radius: 50%;">
                    <img class="img-circle carousel-inne" src="./N诺_成绩排序_files/姜春磊.jpg" alt="头像" style="border-radius: 50%;height: 38px; width: 38px">
                </a>
                <div class="btn-group">
                    <button type="button" style="background-color: white;" class="btn dropdown-toggle" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">
                        <div class="meta" style="color:#696969;font-size:16px;">
                            
                            
                            姜春磊
<i class="fa fa-caret-down"></i>
                            <span class="glyphicon glyphicon-triangle-bottom" style="color:gray;font-size:xx-small"></span>
                        </div>
                    </button>
                    <form action="http://noobdream.com/users/logout/" id="logout" method="post" class="hidden"></form>
                    <div class="dropdown-menu dropdown-menu-right">
                        <!-- 新增代码，通知计数 -->
                        <a class="dropdown-item" href="http://noobdream.com/notifications/unread/">
<i class="fa fa-envelope"></i>
                            message
                            
                        </a>
                        <a href="http://noobdream.com/users/info/20572/" style="text-decoration: none;"><button class="dropdown-item" type="button"><i class="fas fa-user-alt"></i> 姜春磊</button></a>
                        <a href="http://noobdream.com/users/setting/" style="text-decoration: none;"><button class="dropdown-item" type="button"><i class="fas fa-cog"></i> setting</button></a>
                        <a href="javascript:void(0);" onclick="logout()" style="text-decoration: none;"><button class="dropdown-item" type="button"><i class="fas fa-sign-out-alt"></i> sign out</button></a>
                    </div>
                </div>
            </div>
        
    </div>
</div>
<div style="width:100%;height: auto; min-height:calc(100vh - 70px);margin:0 auto;">
        
<!--
<script type="text/x-mathjax-config">
MathJax.Hub.Config({
    showProcessingMessages: false, //关闭js加载过程信息
    messageStyle: "none", //不显示信息
    extensions: ["tex2jax.js"],
    jax: ["input/TeX", "output/HTML-CSS"],
    tex2jax: {
        inlineMath:  [ ["$", "$"] ], //行内公式选择$
        displayMath: [ ["$$","$$"] ], //段内公式选择$$
        skipTags: ['script', 'noscript', 'style', 'textarea', 'pre','code','a'], //避开某些标签
        ignoreClass:"comment-content" //避开含该Class的标签
    },
    "HTML-CSS": {
        availableFonts: ["STIX","TeX"], //可选字体
        showMathMenu: false //关闭右击菜单显示
    }
});
MathJax.Hub.Queue(["Typeset",MathJax.Hub]);
</script>
<script src="//cdn.bootcss.com/mathjax/2.7.0/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>
-->
<div style="width:97%;margin:0 auto;">
	<div class="row justify-content">
		<div class="col-lg-5 bg-white" style="padding:6px;padding-top:8px;padding-right:1px;">
			<div style="height:89vh;padding: 0.6em;;overflow-x:hidden;">
                                <h1 class="mx-auto">成绩排序</h1>
				<a style="float:right;padding:10px;" href="http://noobdream.com/solution_list/1151/"><i class="fa fa-book" aria-hidden="true"></i> 查看题解</a>
                                <a style="float:right;padding:10px;" href="http://noobdream.com/DreamJudge/Issue/problem_status/?judge_states=1&amp;problem_id=1151"><i class="fa fa-pie-chart" aria-hidden="true"></i> 查看答案</a>
				<h5 class="font-weight-bold">题目描述</h5>
                <div class="bg-light p-2 px-3">
                    <span style="font-weight: 500;font-size: small"> Time Limit: 1000 ms</span><br>
                    <span style="font-weight: 500;font-size: small">Memory Limit: 32768 mb</span>
                </div>
<!--开头这里的样式为默认的风格，可以根据自己的喜好更换风格-->
<!--我的高亮效果是zenburn-->
<link rel="stylesheet" href="./N诺_成绩排序_files/xcode.css">
<script src="./N诺_成绩排序_files/highlight.pack.js.下载"></script>
<script>hljs.initHighlightingOnLoad();</script>
				<div class="OjInfo"><div>
<p>查找和排序</p>

<p>题目：输入任意（用户，成绩）序列，可以获得成绩从高到低或从低到高的排列,相同成绩<br>
都按先录入排列在前的规则处理。</p>

<p>示例：<br>
jack&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;70<br>
peter&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;96<br>
Tom&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;70<br>
smith&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;67</p>

<p>从高到低&nbsp;&nbsp;成绩<br>
peter&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;96<br>
jack&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;70<br>
Tom&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;70<br>
smith&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;67</p>

<p>从低到高</p>

<p>smith&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;67</p>

<p>jack&nbsp; &nbsp; &nbsp; 70<br>
Tom&nbsp; &nbsp; &nbsp; 70<br>
peter&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;96</p>
</div></div>
				<h5 class="font-weight-bold">输入输出格式</h5>
				<div class="Problem-content">
					<h6 class="font-weight-bold">输入描述:</h6>
					<article class="my-3">
						<pre style="word-wrap:break-word;white-space: pre-wrap;">输入多行，先输入要排序的人的个数，然后输入排序方法0（降序）或者1（升序）再分别输入他们的名字和成绩，以一个空格隔开</pre>
					</article>
				</div>
				<div class="Problem-content">
					<h6 class="font-weight-bold">输出描述:</h6>
					<article class="my-3">
						<pre style="word-wrap:break-word;white-space: pre-wrap;">按照指定方式输出名字和成绩，名字和成绩之间以一个空格隔开</pre>
					</article>
				</div>
				<h5 class="font-weight-bold">输入输出样例</h5>
				<div class="row">
					<div class="col-md-6">
						<div style="display:flex;">
                                                <div style="flex:1;"><h6 class="font-weight-bold" style="padding-top:2px;">输入样例#:</h6></div>
                                                <div style="flex:1;"><button class="fuzhi" id="input_c" onclick="copy_input()" data-clipboard-action="copy" data-clipboard-target="#input" style="float:right;font-size:12px;margin:2px;margin-right:10px;">复制</button></div>
                                                </div>
						<div class="p-2 bg-light mx-2 rounded mb-1">
							<pre id="input">3
0
fang 90
yang 50
ning 70</pre>
						</div>
					</div>
					<div class="col-md-6">
						<div style="display:flex;">
                                                <div style="flex:1;"><h6 class="font-weight-bold" style="padding-top:2px;">输出样例#:</h6></div>
                                                <div style="flex:1;"><span class="fuzhi" id="output_c" onclick="copy_output()" data-clipboard-action="copy" data-clipboard-target="#output" style="float:right;font-size:12px;margin:2px;margin-right:10px;">复制</span></div>
                                                </div>
						<div class="p-2 bg-light mx-2 rounded mb-1">
							<pre id="output">fang 90
ning 70
yang 50</pre>
						</div>
					</div>
				</div>
				
				
                                <h5 class="font-weight-bold">题目来源</h5>
                                <div class="row">
                                        <div class="col-md-12">
                                                <div class="p-2 bg-light mx-2 rounded mb-1">
                                                        <pre>清华大学上机题</pre>
                                                </div>
                                        </div>
                                </div>

                                
			</div>
		</div>
<script src="https://cdnjs.cloudflare.com/ajax/libs/clipboard.js/1.7.1/clipboard.min.js"></script>
<script type="text/javascript">
function copy_input() {
 var clipboard = new Clipboard('.fuzhi');
                     clipboard.on('success', function (e) {
                       clipboard.destroy();
                     });
                     clipboard.on('error', function (e) {
                       layer.msg('复制失败');
                     });
document.getElementById('input_c').click();  //解决clipboard二次点击生效问题
//document.getElementById('output_c').click();  //解决clipboard二次点击生效问题
                clipboard.destroy();
}
function copy_output() {
 var clipboard = new Clipboard('.fuzhi');
                     clipboard.on('success', function (e) {
                       clipboard.destroy();
                     });
                     clipboard.on('error', function (e) {
                       layer.msg('复制失败');
                     });
//document.getElementById('input_c').click();  //解决clipboard二次点击生效问题
document.getElementById('output_c').click();  //解决clipboard二次点击生效问题
                clipboard.destroy();
}
</script>
<style>
.fuzhi{
        cursor:pointer;
            padding: 1px 3px;
            border: 1px solid #87CEFA;
            border-radius: 4px;
            background:#87CEFA;
            color:white;
        }
.CodeMirror {
    font-family:Courier New;
}
</style>
		<div class="col-lg-7 p-3 bg-dark rounded" style="height:92vh;">
			<form class="d-flex flex-column " method="post" action="http://noobdream.com/DreamJudge/Issue/page/1151/" style="height: 100%;width: 100%;">
				<div class="row mb-2 bttom-border pb-2">
					<div class="dropdown col-lg-2 col-md-2 ">
						<div class="dropdown">
							<a class="btn btn-secondary dropdown-toggle text-white bg-info" id="select_language" href="http://noobdream.com/DreamJudge/Issue/page/1151/#" data-toggle="dropdown">C</a>
							<div class="dropdown-menu select_show">
								<a class="dropdown-item" href="http://noobdream.com/DreamJudge/Issue/page/1151/#" id="csrc" name="C">C</a>
								<a class="dropdown-item" href="http://noobdream.com/DreamJudge/Issue/page/1151/#" id="c++src" name="C++">C++</a>
								<a class="dropdown-item" href="http://noobdream.com/DreamJudge/Issue/page/1151/#" id="java" name="Java">Java</a>
								<a class="dropdown-item" href="http://noobdream.com/DreamJudge/Issue/page/1151/#" id="python" name="Python">Python</a>
							</div>
						</div>
					</div>
					<div class="col-lg-3 col-md-4 col-sm-4 text-info pt-1 reset-btn"><i class="fab fa-rev"></i> 重置</div>
				</div>
				<div class="row" style="flex: 1;overflow: auto;font-family:Courier New;padding-left:1px;padding-right:1px;">
					<pre style="display: none;" id="last_code"></pre>
					<div class="editing-box" style="height: 100%;width: 100%;">
						<textarea id="texteara" name="editor" style="font-family: &quot;Courier New&quot;; display: none;"></textarea><div class="CodeMirror cm-s-base16-dark" style="width: 100%; height: 100%;"><div style="overflow: hidden; position: relative; width: 3px; height: 0px; top: 4px; left: 33px;"><textarea autocorrect="false" autocapitalize="false" spellcheck="false" style="position: absolute; bottom: -1em; padding: 0px; width: 1000px; height: 1em; outline: none;" tabindex="0"></textarea></div><div class="CodeMirror-vscrollbar" tabindex="-1" cm-not-content="true"><div style="min-width: 1px; height: 0px;"></div></div><div class="CodeMirror-hscrollbar" tabindex="-1" cm-not-content="true"><div style="height: 100%; min-height: 1px; width: 0px;"></div></div><div class="CodeMirror-scrollbar-filler" cm-not-content="true"></div><div class="CodeMirror-gutter-filler" cm-not-content="true"></div><div class="CodeMirror-scroll" tabindex="-1"><div class="CodeMirror-sizer" style="margin-left: 29px; margin-bottom: -17px; border-right-width: 13px; min-height: 32px; min-width: 7px; padding-right: 0px; padding-bottom: 0px;"><div style="position: relative; top: 0px;"><div class="CodeMirror-lines" role="presentation"><div role="presentation" style="position: relative; outline: none;"><div class="CodeMirror-measure"><pre><span>xxxxxxxxxx</span></pre></div><div class="CodeMirror-measure"></div><div style="position: relative; z-index: 1;"></div><div class="CodeMirror-cursors"><div class="CodeMirror-cursor" style="left: 4px; top: 0px; height: 24px;">&nbsp;</div></div><div class="CodeMirror-code" role="presentation"><div style="position: relative;"><div class="CodeMirror-gutter-wrapper" style="left: -29px;"><div class="CodeMirror-linenumber CodeMirror-gutter-elt" style="left: 0px; width: 21px;">1</div></div><pre class=" CodeMirror-line " role="presentation"><span role="presentation" style="padding-right: 0.1px;"><span cm-text="">​</span></span></pre></div></div></div></div></div></div><div style="position: absolute; height: 13px; width: 1px; border-bottom: 0px solid transparent; top: 32px;"></div><div class="CodeMirror-gutters" style="height: 45px; left: 0px;"><div class="CodeMirror-gutter CodeMirror-linenumbers" style="width: 29px;"></div></div></div></div>
					</div>
				</div>
				<div class="row">
					<div class="up-btn" style="margin-left:1px;margin-right:1px;"><i class="fas fa-angle-up"></i></div>
					<input type="text" class="d-none">
					<button type="submit" class="mx-2 mt-3 btn btn-primary col-lg-4 col-md-6 col-sm-8" id="codeSubmit">提交代码</button>
					<div class="stu-box mx-1" style="overflow: auto;">
						<article class="py-4 pl-3" id="submit_info">
							<p class="text-info">提交代码后在此处可查看状态</p>
						</article>
					</div>
				</div>
			</form>
			<script>

				//获取代码编辑框，并用codemirror代替textarea
                var myTextarea = $("#texteara")[0];
                var editor = CodeMirror.fromTextArea(myTextarea, {//codemirror参数设置
                    lineNumbers: true,
                    mode:"text/x-c++src",
                    indentUnit: 4,
                    theme:"base16-dark",
                    indentWithTabs: true,
                    matchBrackets: true,
                    styleActiveLine: true,
                });
                editor.setSize("100%" , "100%");//codemirror宽高设置
				editor.setValue($('#last_code').text());
                $(".reset-btn").click(function(){
                    editor.setValue("");//codemirror 内容重置
                });


				$(".dropdown-menu a").click(function(){
					editor.setOption("mode" , "text/x-" + $(this).attr('id'));//codemirror 语言选择
					$("#select_language").text($(this).text());
				});
				$(".dropdown-menu a[name='C']").click();


                var up_btn = $(".up-btn");// 获取提交状态显示按钮
                var flag = 1;//flag = 1 表示提交状态栏为隐藏
                up_btn.click(function(){// 给显示按钮加点击事件，让状态栏显示或隐藏
                    if (flag){
                        $(".stu-box").css('height', '200px');
                        $(this).children().removeClass('fa-angle-up').addClass('fa-angle-down');
                        flag = 0;
                    }
                    else{
                        $(".stu-box").css('height', '0px');
                        $(this).children().removeClass('fa-angle-down').addClass('fa-angle-up');
                        flag = 1;
                    }
                });

                //给提交代码按钮添加ajax事件
				var result = ['', 'Accepted', 'Presentation Error', 'Wrong Answer', 'Time Limit Exceeded', 'Memory Limit Exceeded',
					'Output Limit Exceeded', 'Runtime Error', 'Compilation Error', 'Compile Output Limit','您还没有登录，请先登录！'];
                                var result_color = ['orange', 'green', 'orange', 'red', 'purple', 'purple', 'purple', 'orange',
					'orange', 'orange', 'orange'];
				var er_info=['Please be patient.', 'Congratulations！ Your code <b>accepted</b> the question.',
						'Your <b>output format</b> doesn\'t fit the question.',
						'Your <b>code</b> doesn\'t fit the question.',
						'Your <b>use time</b> doesn\'t fit the question.',
						'Your <b>use Memory</b> doesn\'t fit the question.',
						'Your <b>output</b> is too many.',
						'There was an error in your <b>code</b> at run time.',
						'There was an error in your <b>code</b> when it was compiled.',''
				]
				var last_code = "";
				var last_language = $('#select_language').text();
                $('#codeSubmit').click(function () {
                    var code = editor.getValue();
                    var language = $('#select_language').text();
                    $.ajax({
                        type: 'post',
                        url: '/DreamJudge/Issue/problem_status/',
                        dataType: 'json',
                        data: {
                            'language': language,
                            'editor': code,
                            'prob_no': 1151,
                		},
					beforeSend: function(arg){
						flag = 1;
						up_btn.click();
						if(code != ''){
                            if(last_code === code && last_language == language) {
								$('.stu-box #submit_info').html('<p class="text-danger">Unable to submit same code!</p>');
                            	return false;
							}
                            last_code = code;
                            last_language = language;
						    $('.stu-box #submit_info').html('<p class="text-info">代码测评中...</p>');
						}
						else{
						    $('.stu-box #submit_info').html('<p class="text-danger">Unable to submit empty code!</p>');
						    return false;
						}
					},
                    success: function(ret) {
			if(ret.Error) $('.stu-box #submit_info').html("<p class='text-white'>" + ret.Error.result + "</p>");
							else {
								var _result = "<a href='/DreamJudge/Issue/code/" + ret.Success.runid + "'><p style='font-size:18px;color: "+result_color[ret.Success.result]+";'>" +
										result[ret.Success.result] + "</p></a>";

_result += "<p class='text-info'>" + er_info[ret.Success.result] + "<br/>题目数据通过率为:" + ret.Success.score + "%" + "</p><br/>";
if (ret.Success.result != 1) {
               _result += "<p style=\"color:white;\"><a href=\"" + "/DreamJudge/Issue/code/"+ ret.Success.runid + "/\" target=\"_blank\" style=\"color:white;margin-right:2rem;\"><i class=\"fa fa-wrench\"> </i> 错误数据对比</a><span style=\"width:1rem;\"></span><a href=\"/post/774/\" target=\"_blank\" style=\"color:white;\"><i class=\"fa fa-question-circle\"></i> 错误原因分析</a></p>"
}
	
/*
   _result += "<p class='text-info'>" + er_info[ret.Success.result] + "<br/>题目数据通过率为:" + ret.Success.score + "%" + "</p><br/>";
if (ret.Success.result != 1) {
               _result += "<p style=\"color:white;\"><a href=\"/post/84150/\" target=\"_blank\" style=\"color:white;margin-right:2rem;\"><i class=\"fa fa-wrench\"> </i> 错误数据对比</a><span style=\"width:1rem;\"></span><a href=\"/post/774/\" target=\"_blank\" style=\"color:white;\"><i class=\"fa fa-question-circle\"></i> 错误原因分析</a></p>"
}
*/

								$('.stu-box #submit_info').html(_result);
							}
                    },
                    error: function(err) {
			$('.stu-box #submit_info').html("<p class='text-white'>您还没有登录，请先登录再提交代码！</p>");
                        console.log('error');
                  	  }
             	   	});
                    return false;
                });
			</script>
		</div>
	</div>
</div>

</div>
<style>
.footer {
            margin-top: -50px;
            height: 100%;
            background-color:white;
            z-index: 9999;
            border-top:1.5px solid #EAEAEA;
        }
</style>
<!--
<ul id="jump">
        <li><a id="top" href="#"></a></li>
        <li><a id="qq" href="//shang.qq.com/wpa/qunwpa?idkey=7f6944d9b90771d2ff32fbca76bb356561f274b9d0932a17dca114fd7e297c62" target="_blank"></a></li>
        <li>
                <a id="weixin" href="javascript:void(0)" onmouseover="showEWM()" onmouseout="hideEWM()">
                        <div id="EWM" style="display: none;"><img src="/static/image/right_bar/weixin_code.jpg"></div>
                </a>
        </li>
        <li><a id="reply" href="http://www.noobdream.com/post/61/" target="_blank"></a></li>
        <li>
		<a id="app" href="" onmouseover="showEWMapp()" onmouseout="hideEWMapp()">
        	 	<div id="EWMapp" style="display: none;"><img src="/media/upload/2019/09/19/qq.png"></div>
        	</a>
	</li>
        <li><a id="sina" target="_blank" href="http://weibo.com/noobdream"></a></li>
</ul>
-->
<!--
<div class="footer" style="padding-top:30px;padding-bottom:30px;">
<div style="display:flex;width:78%;max-width:1150px;margin:0 auto;">
<div style="flex:3;">
<div style="height:18px;"></div>
       <img src="/static/image/logo.png"  alt="NoobDream" style= "height:20px;width:auto;"/> 
<font style="font-size:12px;">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The road of your choice, you have to go on !&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;京ICP备15068893号</font>
</div>
<div style="flex:1;">
<div style="display:flex;">
<div style="flex:1;text-align:center;padding-top:10px;">
<a href="http://space.bilibili.com/73422093" target="_blank" class="ch-item" data-v-24bcbaea=""><img src="/static/image/bilibili.png" alt="" data-v-24bcbaea="" style="width:20px;"> <p style="padding-top:3px;color:#444;font-size:12px;">哔哩哔哩</p></a>
</div>
<div style="flex:1;text-align:center;padding-top:10px;"><a href="http://space.bilibili.com/73422093" target="_blank" class="ch-item" data-v-24bcbaea=""><img src="/static/image/weixin.png" alt="" data-v-24bcbaea="" style="width:20px;"> <p style="padding-top:3px;color:#444;font-size:12px;">官方微信</p></a>
</div>
<div style="flex:1;text-align:center;padding-top:10px;"><a href="http://weibo.com/noobdream" target="_blank" class="ch-item" data-v-24bcbaea=""><img src="/static/image/weibo.png" alt="" data-v-24bcbaea="" style="width:20px;"> <p style="padding-top:3px;color:#444;font-size:12px;">官方微博</p></a>
</div>
</div>
</div>
</div>
</div>
-->
<script type="text/javascript">
function showEWM(){
	document.getElementById("EWM").style.display = 'block';
}
function hideEWM(){
	document.getElementById("EWM").style.display = 'none';
}
function showEWMapp(){
        document.getElementById("EWMapp").style.display = 'block';
}
function hideEWMapp(){
        document.getElementById("EWMapp").style.display = 'none';
}
</script>
<!--
<script language="javascript" type="text/javascript">
jQuery(document).on('copy', function(e)
	{
	  var selected = window.getSelection();
	  var selectedText = selected.toString().replace(/\n/g, '<br>');  // Solve the line breaks conversion issue
	  var copyFooter = '链接：' + document.location.href
	                        + '<br>来源：N诺<br><br>';
	  var copyHolder = $('<div>', {id: 'temp', html: copyFooter + selectedText, style: {position: 'absolute', left: '-99999px'}});
	    
	  $('body').append(copyHolder);
	  selected.selectAllChildren( copyHolder[0] );
	  window.setTimeout(function() {
	      copyHolder.remove();
	  },0);
	});
</script>
-->

<script>
        $.ajaxSetup({
            data: { csrfmiddlewaretoken: 'tbvQP0kF95uEuM7ntGicxF8LFC98OWN48ifCQAyK9O5ynrEtWD9OpKKtw31wbm56' },
        });
        $(document).ready(function () {
            
            
        });
    </script>


</body></html>