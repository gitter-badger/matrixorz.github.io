# Left

Left is a clean, whitespace-happy layout for [Jekyll](https://github.com/mojombo/jekyll).

This is designed to be an easy layout to modify for your own blog. It was
extracted from [zachholman.com](http://zachholman.com/), which means it was
battle-hardened from years of posting serious blog posts about emoji and swear
words.

You can see it live right here: <http://zachholman.com/left/>

![Left](http://cl.ly/image/3S2r1p2C0E2B/content)

## Installation

- Install Jekyll: `gem install jekyll`
- [Fork this repository](https://github.com/holman/left/fork)
- Clone it: `git clone https://github.com/YOUR-USER/left`
- Run the jekyll server: `jekyll serve -w`

You should have a server up and running locally at <http://localhost:4000>.

## Customization

Next you'll want to change a few things. Most of them can be changed directly in
[_config.yml](https://github.com/holman/left/blob/master/_config.yml). That's
where we'll pull your name, Twitter username, and things like that.

There's a few other places that you'll want to change, too:

- [CNAME](https://github.com/holman/left/blob/master/CNAME): If you're using
  this on GitHub Pages with a custom domain name, you'll want to change this
  to be the domain you're going to use. All that should be in here is a
  domain name on the first line and nothing else (like: `example.com`).
- [favicon.ico](/images/favicon.ico): This
  is a smaller version of my gravatar for use as the icon in your browser's
  address bar. You should change it to whatever you'd like.
- [apple-touch-icon.png](https://github.com/holman/left/blob/master/apple-touch-icon.png):
  Again, this is my gravatar, and it shows up in iOS and various other apps
  that use this file as an "icon" for your site.

## Deployment

Left is designed to be deployed to [GitHub Pages](http://pages.github.com). It
uses [repository metadata](https://help.github.com/articles/repository-metadata-on-github-pages)
to generate some of your content, like your GitHub URL and avatar information (so you
might not actually see it locally until you push it up to Pages).

All you should have to do is rename your repository on GitHub to be
`username.github.com`. Since everything is on the `gh-pages` branch, you
should be able to see your new site at <http://username.github.io>.

## Licensing

This is [MIT](https://github.com/holman/left/blob/master/LICENSE) with no
added caveats, so feel free to use this on your site without linking back to
me or using a disclaimer or anything silly like that.

If you'd like give me credit somewhere on your blog or tweet a shout out to
[@holman](https://twitter.com/holman), well hey, I'll take it.
=======
# Jekyll-Bootstrap

The quickest way to start and publish your Jekyll powered blog. 100% compatible with GitHub pages

## Usage

For all usage and documentation please see: <http://jekyllbootstrap.com>

## Version

0.3.0 - stable and versioned using [semantic versioning](http://semver.org/).

**NOTE:** 0.3.0 introduces a new theme which is not backwards compatible in the sense it won't _look_ like the old version.
However, the actual API has not changed at all.
You might want to run 0.3.0 in a branch to make sure you are ok with the theme design changes.

## Contributing 

This repository tracks 2 projects:

- **Jekyll-Bootstrap Framework.**  
  The framework for which users should clone and build their blog on top of is available in the master branch.
  
  To contribute to the framework please make sure to checkout your branch based on `jb-development`!!
  This is very important as it allows me to accept your pull request without having to publish a public version release.
  
  Small, atomic Features, bugs, etc.   
  Use the `jb-development` branch but note it will likely change fast as pull requests are accepted.   
  Please rebase as often as possible when working.   
  Work on small, atomic features/bugs to avoid upstream commits affecting/breaking your development work.
  
  For Big Features or major API extensions/edits:   
  This is the one case where I'll accept pull-requests based off the master branch.
  This allows you to work in isolation but it means I'll have to manually merge your work into the next public release.
  Translation : it might take a bit longer so please be patient! (but sincerely thank you).
 
- **Jekyll-Bootstrap Documentation Website.**    
  The documentation website at <http://jekyllbootstrap.com> is maintained in the gh-pages branch.
  Please fork and contribute documentation additions to this branch only.

The master and gh-pages branch do not share the same ancestry. Please treat them as completely separate git repositories!
=======
## Contributing


To contribute to the framework please make sure to checkout your branch based on `jb-development`!!
This is very important as it allows me to accept your pull request without having to publish a public version release.

Small, atomic Features, bugs, etc.
Use the `jb-development` branch but note it will likely change fast as pull requests are accepted.
Please rebase as often as possible when working.
Work on small, atomic features/bugs to avoid upstream commits affecting/breaking your development work.

For Big Features or major API extensions/edits:
This is the one case where I'll accept pull-requests based off the master branch.
This allows you to work in isolation but it means I'll have to manually merge your work into the next public release.
Translation : it might take a bit longer so please be patient! (but sincerely thank you).

**Jekyll-Bootstrap Documentation Website.**

The documentation website at <http://jekyllbootstrap.com> is maintained at https://github.com/plusjade/jekyllbootstrap.com


## License

[MIT](http://opensource.org/licenses/MIT)
