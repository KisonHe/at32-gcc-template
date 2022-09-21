import os
import subprocess
# No need to use jinja this is so simple
try:
    from jinja2 import Template
except Exception as e:
    print("Fail to import jinja2, exiting...")
    exit(0)
git_result = (
    subprocess.check_output(["bash", "git_ver.sh"])
    .strip()
    .decode("utf-8")
)
h_template_file = open("h_git_ver.inja","r")
h_template_string = h_template_file.read()
h_template_file.close()

template = Template(h_template_string)
header_render_result = template.render(git_result=git_result)
# os.makedirs(os.path.dirname(os.path.join(args.output,"stringtable.h")), exist_ok=True)
h_file = open("git_ver.h","w+")
h_file.write(header_render_result)
h_file.close()
