# Cactive

This is my playground for experimenting with Ruby C Extensions. I generally
require some project, or direction to learn things so I decided to work on implementing
ActiveSupport::CoreExtensions in C. No, I'm not saying this should be a widely used Gem,
nor that Core Extensions (even in Ruby) are good. I mostly think its a
good way to dig my hands deep into the Ruby C APIs and figure out what the hell
Ruby does to make my days awesome.

Suggestions, comments or concerns? Check out the issues page.

## Installation

Add this line to your application's Gemfile:

    gem 'cactive', git: "http://github.com/jphenow/cactive.git"

And then execute:

    $ bundle

## Contributing

1. Fork it
2. Create your feature branch (`git checkout -b my-new-feature`)
3. Commit your changes (`git commit -am 'Add some feature'`)
4. Push to the branch (`git push origin my-new-feature`)
5. Create new Pull Request
