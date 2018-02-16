TEMPLATE = subdirs

SUBDIRS += \
    gallery-mobile \
    gallery-core

gallery-mobile.depends = gallery-core
