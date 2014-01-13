---
layout: post
title: "nginx permission root"
description: ""
category: 
tags: []
---
{% include JB/setup %}

nginx 13:permission denied solved:
http://serverfault.com/questions/246609/trouble-with-nginx-and-serving-from-multiple-directories-under-the-same-domain

The root directive is the problem here. Quote from the doc:

note: Keep in mind that the root will still append the directory to the request so that a request for "/i/top.gif" will not look in "/spool/w3/top.gif" like might happen in an Apache-like alias configuration where the location match itself is dropped. Use the alias directive to achieve the Apache-like functionality.

Basically, only use root for real roots: if the content is to be at / use root. If it's going to end on a subfolder, use alias:

location  /map/ {
  alias  /home/user/public_html/map/;
}
Also check what user nginx is running as and make sure that this user can access /home/user/public_html/map

share|improve this answer
edited Jan 26 '12 at 15:30

answered Mar 12 '11 at 15:39

coredump
8,35011131
It shows up properly in access.log now, as /map/, but I still get a 403 forbidden error, public_html/ and every directory under it is 777, and I've tried chowning it to nginx and root, but I still get the 403 error. Any ideas? – Phase Mar 12 '11 at 17:25
@phase well I never had a similar problem, but check this link and this other one. Looks like lack of permission to read on each directory of the whole path you are serving (in your case, home, user, public_html and map). – coredump Mar 12 '11 at 20:00
You need to be careful with /s when using alias. The location and alias you posted will strip the / from the request, but the alias doesn't add it back, so a request for /map/foo.html will actually look for /home/user/public_htmlfoo.html. When the location prefix matches the alias suffix, it's easier to use use root /home/user/public_html. You could also fix it by just adding a / onto the end of the alias /home/user/public_html/map/; 