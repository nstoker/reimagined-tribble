TEMPLATE = subdirs

SUBDIRS += \
    filter-plugin-designer \
    image-filter

image-filter.depends = filter-plugin-designer
