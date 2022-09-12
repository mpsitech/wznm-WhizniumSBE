<template>
	<v-card v-if="initdone" class="pa-3 my-3 mx-auto" elevation="4">
		<v-card-title>
			<v-row>
				<v-col cols="4">
					<div>
						<span>{{Cpt}}</span>
					</div>
				</v-col>
				<v-col cols="8" align="end">
					&#160;
					<v-btn
						v-if="statapp.srefIxWznmVExpstate=='regd'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButClipboardClick()"
						:value="1"
					>
						<v-icon color="white">mdi-clipboard</v-icon>
					</v-btn>
					&#160;
					<v-btn
						v-if="statapp.srefIxWznmVExpstate=='regd'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButCrdopenClick('ButViewClick')"
						:value="1"
						:disabled="!statshr.ButViewActive"
					>
						<v-icon color="white">mdi-book-arrow-up</v-icon>
					</v-btn>
					&#160;&#160;
					<v-btn
						v-if="statapp.srefIxWznmVExpstate=='regd'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButCrdopenClick('ButNewClick')"
						:value="1"
					>
						<v-icon color="white">mdi-file-plus</v-icon>
					</v-btn>
					&#160;
					<v-btn
						v-if="statapp.srefIxWznmVExpstate=='regd'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButClick('ButDeleteClick')"
						:value="1"
						:disabled="!statshr.ButDeleteActive"
					>
						<v-icon color="white">mdi-file-remove</v-icon>
					</v-btn>
					&#160;&#160;
					&#160;
					<v-btn
						v-if="statapp.srefIxWznmVExpstate=='regd'"
						fab
						small
						light
						color="primary"
						v-on:click="statapp.srefIxWznmVExpstate='mind'"
						:value="1"
					>
						<v-icon color="white">mdi-minus-circle</v-icon>
					</v-btn>
					&#160;
					<v-btn
						v-if="statapp.srefIxWznmVExpstate=='mind'"
						fab
						small
						light
						color="primary"
						v-on:click="statapp.srefIxWznmVExpstate='regd'"
						:value="1"
					>
						<v-icon color="white">mdi-plus-circle</v-icon>
					</v-btn>
				</v-col>
			</v-row>
		</v-card-title>

		<v-card-text
			v-if="statapp.srefIxWznmVExpstate=='regd'"
		>
			<v-data-table
				:headers="headers"
				:items="contapp.rows"
				:items-per-page="10"
				item-key="jnum"
				single-select
				show-select
				class="elevation-1 my-3"
				v-on:item-selected="handleSelect"
			/>

			<v-row>
				<v-col align="end">
					<v-tooltip left>
						<template v-slot:activator="{on,attrs}">
							<v-btn
								fab
								small
								light
								v-bind="attrs"
								v-on="on"
								:color="fiFCsiQst.sref == 'ong' ? 'orange' : fiFCsiQst.sref == 'red' ? 'red' : fiFCsiQst.sref == 'yel' ? 'yellow' : fiFCsiQst.sref == 'grn' ? 'green' : 'primary'"
								v-on:click="handleButClick('ButRefreshClick')"
							>
								<v-icon color="white">mdi-refresh</v-icon>
							</v-btn>
						</template>
						{{fiFCsiQst.tit1}}
					</v-tooltip>
				</v-col>
			</v-row>
		</v-card-text>
	</v-card>
</template>

<script>
	import Wznm from '../../scripts/Wznm';

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWznmVer1NJob',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWznmVer1NJob.mounted() with scrJref = " + this.scrJref);

			const dpchapp = {
				"DpchAppWznmInit": {
					"scrJref": this.scrJref
				}
			};

			this.$emit('request', {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppInitReply"});
		},

		methods: {
			/*
			<!-- IP cust - INSERT -->
			*/

			handleButClick: function(ctlsref) {
				const dpchapp = {
					"DpchAppWznmVer1NJobDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			handleButClipboardClick: function() {
				/*
				*/
				Wznm.copyToClipboard(document, this.continf, this.rst, this.statshrqry, this.tag,
							["Ref"],
							["ref"]);
				/*
				*/
			},

				handleButCrdopenClick: function(ctlsref) {
				const dpchapp = {
					"DpchAppWznmVer1NJobDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDoCrdopenReply"});
			},

			handleSelect: function(obj) {
				var stgiacqry = this.stgiacqry;

				if (!obj.value) stgiacqry.jnum = 0;
				else stgiacqry.jnum = obj.item.jnum;

				const dpchapp = {
					"DpchAppWznmVer1NJobData": {
						"scrJref": this.scrJref,
						"StgIacQryWznmVer1NJob": stgiacqry
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			updateEng: function(mask) {
				var dpchapp = {
					"scrJref": this.scrJref
				}

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWznmVer1NJob"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWznmVer1NJobData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWznmVer1NJobData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContInfWznmVer1NJob) this.continf = dpcheng.ContInfWznmVer1NJob;
				if (dpcheng.FeedFCsiQst) this.feedFCsiQst = dpcheng.FeedFCsiQst;
				if (dpcheng.StatAppWznmVer1NJob) this.statapp = dpcheng.StatAppWznmVer1NJob;
				if (dpcheng.StatShrWznmVer1NJob) this.statshr = dpcheng.StatShrWznmVer1NJob;
				if (dpcheng.StgIacWznmVer1NJob) this.stgiac = dpcheng.StgIacWznmVer1NJob;
				if (dpcheng.TagWznmVer1NJob) {
					Wznm.unescapeBlock(dpcheng.TagWznmVer1NJob);
					this.tag = dpcheng.TagWznmVer1NJob;
				}
				if (dpcheng.ListWznmQVer1NJob) this.rst = dpcheng.ListWznmQVer1NJob;
				if (dpcheng.StatAppQryWznmVer1NJob) this.statappqry = dpcheng.StatAppQryWznmVer1NJob;
				if (dpcheng.StatShrQryWznmVer1NJob) this.statshrqry = dpcheng.StatShrQryWznmVer1NJob;
				if (dpcheng.StgIacQryWznmVer1NJob) this.stgiacqry = dpcheng.StgIacQryWznmVer1NJob;
				/*
				<!-- IP mergeDpchEngData - END -->
				*/

				if (dpcheng.TagWznmVer1NJob) {
					var tcos = [];

					/*
					*/
					tcos.push({value: "jnum", text: "jnum"}, {value: "TcoRef", text: this.tag.TcoRef});
					/*
					*/

					this.contapp.tcos = tcos;
				}

				if (dpcheng.ListWznmQVer1NJob) {
					var rows = [];

					for (var i = 0; i < this.rst.length; i++) {
						var rec = this.rst[i];
						/*
						*/
						rows.push({jnum: rec["jnum"], TcoRef: rec["ref"]})
						/*
						*/

					}

					this.contapp.rows = rows;
				}
			},

			handleReply: function(obj) {
				if (obj.then == "handleDpchAppInitReply") this.handleDpchAppInitReply(obj.dpcheng);
				else if (obj.then == "handleDpchAppDataDoReply") this.handleDpchAppDataDoReply(obj.srefIxWznmVDpch, obj.dpcheng);
				else if (obj.then == "handleDpchAppDoCrdopenReply") this.handleDpchAppDoCrdopenReply(obj.srefIxWznmVDpch, obj.dpcheng);
			},

			handleDpchAppInitReply: function(dpcheng) {
				this.mergeDpchEngData(dpcheng);

				this.initdone = true;
			},

			handleDpchAppDataDoReply: function(srefIxWznmVDpch, dpcheng) {
				if (srefIxWznmVDpch == "DpchEngWznmVer1NJobData") this.mergeDpchEngData(dpcheng);
			},

			handleDpchAppDoCrdopenReply: function(srefIxWznmVDpch, dpcheng) {
				if (srefIxWznmVDpch == "DpchEngWznmConfirm")
					if (dpcheng.accepted)
						this.$emit("crdopen", {srefCrd: dpcheng.sref, scrJrefCrd: dpcheng.scrJref, newtabNotInplace: false});
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWznmVDpch == "DpchEngWznmVer1NJobData") this.mergeDpchEngData(obj.dpcheng);
				/*
				*/
			}
		},

		computed: {
			/*
			*/
			/*
			*/
			Cpt: function() {
				if (this.statapp.srefIxWznmVExpstate == "mind") return(this.tag.Cpt + " (" + this.statshrqry.ntot + ")");
				return this.tag.Cpt;
			},
			/*
			*/

			headers: function() {
				return this.contapp.tcos.filter(x => x.value != "jnum")
			},

			fiFCsiQst: function() {
				if (this.feedFCsiQst && this.continf)
					for (var i = 0; i < this.feedFCsiQst.length; i++)
						if (this.feedFCsiQst[i].num == this.continf.numFCsiQst) return this.feedFCsiQst[i];

				return {sref: "gry", tit1: "invalid"}
			}
		},

		data: () => ({
			initdone: false,

			/*
			*/
			continf: null,

			feedFCsiQst: null,

			statapp: null,

			statshr: null,

			stgiac: null,

			tag: null,

			rst: null,

			statappqry: null,

			statshrqry: null,

			stgiacqry: null,

			contapp: {
				tcos: [],
				rows: [],

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
