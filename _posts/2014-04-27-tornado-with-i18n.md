---
layout: post
title: "tornado with i18n"
description: ""
category: 
tags: []
---
{% include JB/setup %}
i18n是国际化的简称（Internationalization,去掉开始的I和最后的N，中间一共18个字符）。
tornado中使用i18n需要下面两个工具
两个工具:pygettext,msgfmt，两个相关文件:po文件和mo文件

pygetext和msgfmt的使用方法：

编写python代码文件 test.py
   
    from gettext import gettext as _
    print _("well down")
    print _("good")

pygetext test.py

生成messages.pot文件,更改文件后缀
mv messages.pot messages.po
配置msgstr值

生成一个名为messages.mo文件：
msgfmt messages.po

建立目录locale/cn/LC_MESSAGES/

mv messages.po locale/cn/LC_MESSAGES

cn目录是所对应的语言，LC_MESSAGES是gettext.py文件里要求的
mo文件必须和所定义的域同名
gettext.py中有
modfile=os.path.join(localedir,lang,'LC_MESSAGES','%s.mo' %domain)

测试：
    $python
    >>>gettext.install('messages','./locale',unicode=True)
三个参数：
作用域名，用于限定翻译文件的主名
路径，存放翻译文件的路径
unicode，是否使用unicode（如果应用程序是unicode的，此处应设为True)

    >>>gettext.translation('messages','./locale',languages=['cn']).install(True)
    >>>print _("good")

在tornado中使用时:
    
    $xgettext -L python -k=_ -o openquant.po $(find . -name \*.py) $(find template/ -name \*.html)
查找所有需要翻译的相关项生成 po 文件

    $msgfmt openquant.po -o locale/zh_CN/LC_MESSAGES/openquant.mo
生成mo文件

完成相关文件的生成后，需要在代码中加载:

    tornado.locale.load_gettext_translations(options.I18N_PATH,"openquant")

handler中自定义get_user_locale函数：

    def get_user_locale(self):
        #zh_CN or en_US
        user_locale = self.get_cookie("user_locale")

        if user_locale:
            return tornado.locale.get(user_locale)

        return None


参考文章:
[iMind](http://www.ylinux.org/imind/167)



