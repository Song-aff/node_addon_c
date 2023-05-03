cmd_Release/add.node := ln -f "Release/obj.target/add.node" "Release/add.node" 2>/dev/null || (rm -rf "Release/add.node" && cp -af "Release/obj.target/add.node" "Release/add.node")
