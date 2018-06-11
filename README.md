2018.6.11 
思路：
  先将原先的软件反编译出CocosUI工程，成为参照物使用，然后复制一份，只替换资源，不改变层级关系和命名规则
  问题1 加载csb后出错
      命名出错
  问题2 加载csb后没有图片
      csb和资源需放到res文件下
  问题3 缩放比问题
      修改 ExternalFun.lua脚本 第325行
      if csbFile == "GameLayer.csb" then
		    csbnode:setScale(1335 / 1136)
	    end
      设置全局缩放
