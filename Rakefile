require "bundler/gem_tasks"

require 'rake/extensiontask'

Rake::ExtensionTask.new('array') do |ext|
  ext.ext_dir = File.join 'ext', 'array'
  ext.lib_dir = File.join 'lib', 'cactive'
  ext.name = 'array'
end

Rake::ExtensionTask.new('string') do |ext|
  ext.ext_dir = File.join 'ext', 'string'
  ext.lib_dir = File.join 'lib', 'cactive'
  ext.name = 'string'
end
